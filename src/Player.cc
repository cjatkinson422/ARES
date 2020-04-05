#include "Player.hh"
#include "GLContext.hh"
#include "Logger.hh"




Player::Player():player_controller(PlayerController(this)),camera(Camera()), physics_object(PhysicsObject(position, rotation)){
    this->position = {5.0,0.0,0.0};
    this->rotation = {1.0,0.0,0.0,0.0};
    this->camera.position = this->position;
    this->camera.rotation = this->rotation;
    this->camera.updateViewMatrix();
    this->player_controller.use();

}

void Player::tick(double delta_time){
    // Add the change in position since last frame
    this->physics_object.tick(delta_time);
    this->camera.position = this->position;
    this->camera.rotation = this->rotation;
    this->camera.updateViewMatrix();

    GLContext::getInstance()->getShader("julia")->setUniformMat4("projection",this->camera.getViewProjectionMatrix());
}

void Player::draw(){

}

double Player::get_eva_thrust(){
    return 10.0;
}
double Player::get_eva_torque(){
    return 10.0;
}
