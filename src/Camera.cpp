#include "Camera.hpp"
#include "InputHandler.hpp"
#include <functional>

using std::placeholders::_1;
using std::placeholders::_2;
using std::bind;

Camera* Camera::instance;
Camera::Camera(){
    InputHandler::getInstance()->set_RESIZE_callback(bind(&Camera::windowResizeCallback, this, _1, _2));
    InputHandler::getInstance()->set_SCROLL_callback(bind(&Camera::scrollCallback,this,_1,_2));
}
Camera* Camera::getInstance(){ 
    if(!instance)
        instance = new Camera();
    return instance;
}
void Camera::windowResizeCallback(GLint width, GLint height){

}
void Camera::scrollCallback(GLdouble xoffset, GLdouble yoffset){

}