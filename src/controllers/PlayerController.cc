#include <functional>
#include "PlayerController.hh"
#include "engine/Shader.hh"
#include "objects/Player.hh"
#include "engine/Window.hh"


PlayerController::PlayerController(Player* player){
    this->player = player;
}


void PlayerController::use(){
    InputHandler* input_handler = InputHandler::getInstance();
    input_handler->set_W_callback([this](const double& delta_time){this->eva_control_thrust_forward(delta_time);});
    input_handler->set_S_callback([this](const double& delta_time){this->eva_control_thrust_backward(delta_time);});

    input_handler->set_A_callback([this](const double& delta_time){this->eva_control_thrust_left(delta_time);});
    input_handler->set_D_callback([this](const double& delta_time){this->eva_control_thrust_right(delta_time);});

    // Assign the E and Q keys to empty lambdas since the EVA slew function handles these inputs
    input_handler->set_E_callback([](const double& delta_time){});
    input_handler->set_Q_callback([](const double& delta_time){});

    input_handler->set_SPACE_callback([this](const double& delta_time){this->eva_control_thrust_up(delta_time);});
    input_handler->set_LSHIFT_callback([this](const double& delta_time){this->eva_control_thrust_down(delta_time);});

    //input_handler->set_CURSOR_callback([this](GLdouble xoffset, GLdouble yoffset){this->eva_slew(xoffset, yoffset);});
    input_handler->set_CURSOR_TICK_callback([this](const double& delta_time, double x_strength, double y_strength){this->eva_slew(delta_time, x_strength, y_strength);});

    input_handler->set_ESC_callback([](const double& delta_time){glfwSetWindowShouldClose(Window::getGLFWwindow(),1); glfwSetInputMode(Window::getGLFWwindow(), GLFW_CURSOR, GLFW_CURSOR_NORMAL); });
}

void PlayerController::eva_control_thrust_forward(const double& delta_time){
    vec3 backward = this->player->local_attitude.rotate(vec3::unit_z);
    double impulse = -1.0 * player->get_eva_thrust() * delta_time;
    this->player->physics_object.add_impulse(backward * impulse);
}
void PlayerController::eva_control_thrust_backward(const double& delta_time){
    vec3 backward = this->player->local_attitude.rotate(vec3::unit_z);
    double impulse = player->get_eva_thrust() * delta_time;
    this->player->physics_object.add_impulse(backward * impulse);
}

void PlayerController::eva_control_thrust_left(const double& delta_time){
    vec3 right = this->player->local_attitude.rotate(vec3::unit_x);
    double impulse = -1.0 * player->get_eva_thrust() * delta_time;
    this->player->physics_object.add_impulse(right * impulse);
}
void PlayerController::eva_control_thrust_right(const double& delta_time){
    vec3 right = this->player->local_attitude.rotate(vec3::unit_x);
    double impulse = player->get_eva_thrust() * delta_time;
    this->player->physics_object.add_impulse(right * impulse);
}

void PlayerController::eva_control_thrust_up(const double& delta_time){
    vec3 up = this->player->local_attitude.rotate(vec3::unit_y);
    double impulse = player->get_eva_thrust() * delta_time;
    this->player->physics_object.add_impulse(up * impulse);
}
void PlayerController::eva_control_thrust_down(const double& delta_time){
    vec3 up = this->player->local_attitude.rotate(vec3::unit_y);
    double impulse = -1.0 * player->get_eva_thrust() * delta_time;
    this->player->physics_object.add_impulse(up * impulse);
}


void PlayerController::eva_slew(const double& delta_time, double cursor_x, double cursor_y){
    // This function is used as a tick callback for eva slewing based upon the current cursor
    // position. It also adjusts the cursor position in an attempt to re-center it slowly.
    // If EVA_ANGULAR_DAMPING is enabled then the function also attempts to slow the rotation
    // of the player automatically using the maximum available eva torque, but only does so if
    // the cursor is not centered (i.e. if the player is attempting to rotate themselves)
    //
    // The cursor_x and cursor_y represent the screen position of the cursor at the time that this
    // function is called by InputHandler.
    //
    // X is measured from left to right
    // Y is measured from top to bottom
    // Input values are adjusted such that the postion 0,0 is the center of the screen
    
    // Get the input handler instance
    InputHandler* input_handler = InputHandler::getInstance();

    // Flip the y position so that it is measured from bottom to top
    cursor_y = -cursor_y;

    // Get the mouse location angle from its current position
    double slew_angle = atan2(cursor_y, cursor_x);
    // Define the maximum cursor position radius. Then use it to bound and normalize the input
    double max_slew_radius = 500.0; 
    double min_slew_radius = 15.0;
    double current_cursor_radius = sqrt(cursor_x*cursor_x + cursor_y*cursor_y);
    if(current_cursor_radius < 1e-2){
        current_cursor_radius = 0.0;
        slew_angle = 0.0;
    }
    current_cursor_radius = std::min( current_cursor_radius, max_slew_radius );

    // Determine the bounded cursor x position (bounded to max_slew_radius)
    cursor_x = cos(slew_angle) * current_cursor_radius;
    cursor_y = sin(slew_angle) * current_cursor_radius;


    // find the strength factor to multiply the maximum eva thrusting torque by
    // X is negative since moving the cursor to the right sould cause negative rotation about the y axis (up)
    // Y is positive since moving the cursor up sould cause positive rotation about the x axis (right)
    bool is_actively_slewing = false;
    double h_strength = 0.0;  // horizontal
    double v_strength =  0.0; //vertical
    if(current_cursor_radius > min_slew_radius){
        h_strength =  cursor_x / max_slew_radius;
        v_strength =  cursor_y / max_slew_radius;
        is_actively_slewing = true;
    }

    // determine the strength of the roll torque
    // NOTE: these types of functions belong in the input handler, but as rotations are coupled and this
    // function is already ticked every frame, this exception was made.
    double z_strength = 0.0;
    if(glfwGetKey(Window::getInstance()->getGLFWwindow(), GLFW_KEY_Q) == GLFW_PRESS){
        z_strength += 0.5;
        is_actively_slewing = true;
    }
    if(glfwGetKey(Window::getInstance()->getGLFWwindow(), GLFW_KEY_E) == GLFW_PRESS){
        z_strength -= 0.5;
        is_actively_slewing = true;
    }
    
    // Determine the magniutde of the thrusing torques to be applied in standardized units (N-m)
    double x_torque_magnitude = player->get_eva_torque() *  v_strength;
    double y_torque_magnitude = player->get_eva_torque() * -h_strength;
    double z_torque_magnitude = player->get_eva_torque() *  z_strength;

    // Get the torques for each axis
    vec3 pitch_torque  = vec3::unit_x * x_torque_magnitude;
    vec3 yaw_torque    = vec3::unit_y * y_torque_magnitude;
    vec3 roll_torque   = vec3::unit_z * z_torque_magnitude;
    // Add the resulting torques from both eva thrusters
    vec3 torque_body_frame = yaw_torque + pitch_torque + roll_torque;

    // Add the impulse to the Player's physics object
    this->player->physics_object.add_body_frame_torque(torque_body_frame, delta_time);

    // Update the HUD shader with the crosshair location
    Shader::HUD.setUniform1f("x", cursor_x / max_slew_radius);
    Shader::HUD.setUniform1f("y", cursor_y / max_slew_radius);

    // Set the screen position of the cursor to the bounded value (making sure to flip the y value back)
    cursor_x = cursor_x * exp(-delta_time*3.0);
    cursor_y = cursor_y * exp(-delta_time*3.0);
    input_handler->setCursorPos(cursor_x, -cursor_y);

    // If the player is not actively slewing, and damping is enabled, then damp the players
    // rotation with the thrusters instead. The eva_rotational_damp function uses maximum available torque
    if(!is_actively_slewing){
        this->eva_rotational_damp(delta_time);
    }
}

void PlayerController::eva_rotational_damp(const double& delta_time){
    this->player->physics_object.add_body_frame_damping_torque(player->get_eva_torque(), delta_time);
}
void PlayerController::eva_translational_damp(const double& delta_time){
    this->player->physics_object.add_damping_impulse(this->player->get_eva_thrust()*delta_time);
}