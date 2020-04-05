#include <functional>
#include "PlayerController.hh"
#include "GLContext.hh"
#include "Player.hh"

PlayerController::PlayerController(Player* player){
    this->player = player;
}


void PlayerController::use(){
    InputHandler* input_handler = InputHandler::getInstance();
    input_handler->set_W_callback([this](double delta_time){this->eva_control_thrust_forward(delta_time);});
    input_handler->set_S_callback([this](double delta_time){this->eva_control_thrust_backward(delta_time);});

    input_handler->set_A_callback([this](double delta_time){this->eva_control_thrust_left(delta_time);});
    input_handler->set_D_callback([this](double delta_time){this->eva_control_thrust_right(delta_time);});

    input_handler->set_SPACE_callback([this](double delta_time){this->eva_control_thrust_up(delta_time);});
    input_handler->set_LSHIFT_callback([this](double delta_time){this->eva_control_thrust_down(delta_time);});

    //input_handler->set_CURSOR_callback([this](GLdouble xoffset, GLdouble yoffset){this->eva_slew(xoffset, yoffset);});
    input_handler->set_CURSOR_TICK_callback([this](double delta_time, double x_strength, double y_strength){this->eva_slew(delta_time, x_strength, y_strength);});

    input_handler->set_ESC_callback([](double delta_time){glfwSetWindowShouldClose(Window::getGLFWwindow(),true);});
}

void PlayerController::eva_control_thrust_forward(double delta_time){
    vec3 backward = this->player->rotation.rotate(vec3::unit_z);
    double impulse = -1.0 * player->get_eva_thrust() * delta_time;
    this->player->physics_object.add_impulse(backward * impulse);
}
void PlayerController::eva_control_thrust_backward(double delta_time){
    vec3 backward = this->player->rotation.rotate(vec3::unit_z);
    double impulse = player->get_eva_thrust() * delta_time;
    this->player->physics_object.add_impulse(backward * impulse);
}

void PlayerController::eva_control_thrust_left(double delta_time){
    vec3 right = this->player->rotation.rotate(vec3::unit_x);
    double impulse = -1.0 * player->get_eva_thrust() * delta_time;
    this->player->physics_object.add_impulse(right * impulse);
}
void PlayerController::eva_control_thrust_right(double delta_time){
    vec3 right = this->player->rotation.rotate(vec3::unit_x);
    double impulse = player->get_eva_thrust() * delta_time;
    this->player->physics_object.add_impulse(right * impulse);
}

void PlayerController::eva_control_thrust_up(double delta_time){
    vec3 up = this->player->rotation.rotate(vec3::unit_y);
    double impulse = player->get_eva_thrust() * delta_time;
    this->player->physics_object.add_impulse(up * impulse);
}
void PlayerController::eva_control_thrust_down(double delta_time){
    vec3 up = this->player->rotation.rotate(vec3::unit_y);
    double impulse = -1.0 * player->get_eva_thrust() * delta_time;
    this->player->physics_object.add_impulse(up * impulse);
}

void PlayerController::eva_slew(double delta_time, double cursor_x, double cursor_y){
    InputHandler* input_handler = InputHandler::getInstance();

    // Determine the bounded cursor x position, should be between -1000 and 1000
    if(cursor_x >= 0.0)
        cursor_x = std::min(cursor_x,1000.0);
    else
        cursor_x = std::max(cursor_x, -1000.0);
    
    // Determine the bounded cursor y position, should be between -1000 and 1000
    if(cursor_y >= 0.0)
        cursor_y = std::min(cursor_y, 1000.0);
    else
        cursor_y = std::max(-1000.0, cursor_y);
    
    // Sets the glfw cursor position to match the bounded position
    // NOTE: Maybe not necessary?
    input_handler->setCursorPos(cursor_x, cursor_y);

    // find the strength factor to multiply the maximum eva thrusting torque by
    double x_strength = -cursor_x / 1000.0;
    double y_strength = -cursor_y / 1000.0;

    // Determine the magniutde of the thrusing torques to be applied in standardized units (N-m)
    double x_torque_magnitude = player->get_eva_torque() * x_strength;
    double y_torque_magnitude = player->get_eva_torque() * y_strength;

    // Get the torques for each axis
    vec3 yaw_torque = vec3::unit_y * x_torque_magnitude;
    vec3 pitch_torque = vec3::unit_x * y_torque_magnitude;
    // Add the resulting torques from both eva thrusters
    vec3 torque_body_frame = yaw_torque + pitch_torque;

    // Add the impulse to the Player's physics object
    this->player->physics_object.add_angular_impulse(torque_body_frame, delta_time);

    //input_handler->setCursorPos(std::min(cursor_x, 1000.0));

}