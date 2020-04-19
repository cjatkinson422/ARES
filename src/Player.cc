#include "Player.hh"
#include "GLContext.hh"
#include "Logger.hh"




Player::Player():player_controller(PlayerController(this)), physics_object(PhysicsObject(local_position, local_attitude)){
    this->local_position = {0.0,2.0,5.0};
    this->local_attitude = quaternion(vec3(1.0,0.0,0.0), 0.0);
    this->player_controller.use();

    this->camera.parent_obj = this;

}

void Player::tick(const double& delta_time, Scene& scene){
    // Add the change in position since last frame
    this->physics_object.tick(delta_time);
}

void Player::render(){
    hud.render();
}

double Player::get_eva_thrust(){
    return 10.0;
}
double Player::get_eva_torque(){
    return 50.0;
}

Camera& Player::get_camera(){
    return camera;
}