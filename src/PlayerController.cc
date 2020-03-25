#include <functional>
#include "PlayerController.hh"
#include "GLContext.hh"
#include "Player.hh"

PlayerController::PlayerController(){
    /*
    InputHandler* input_handler = InputHandler::getInstance();
    input_handler->set_W_callback([this](){
        GLContext::getInstance()->getShader("julia")->setUniform1f("y",this->position.y); this->position.y+=0.01;});
    input_handler->set_S_callback([this](){
        GLContext::getInstance()->getShader("julia")->setUniform1f("y",this->position.y); this->position.y-=0.01;});
    input_handler->set_A_callback([this](){
        GLContext::getInstance()->getShader("julia")->setUniform1f("x",this->position.x); this->position.x-=0.01;});
    input_handler->set_D_callback([this](){
        GLContext::getInstance()->getShader("julia")->setUniform1f("x",this->position.x); this->position.x+=0.01;});
    */
    
    
}

void PlayerController::eva_control_thrust_forward(double delta_time){
    vec3 forward = this->player->attitude.rotate(vec3::unit_x);
}