#include "Camera.hh"
#include "InputHandler.hh"
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

inline mat4 ProjectionMat(double fovy, double aspect, double nearClip, double farClip) {
	mat4 ret = mat4::zeros();
	double tanHalf = tan(fovy / 2.0);

	ret[0][1] = 1.0 / (aspect*tanHalf); // n/t

	ret[1][2] = 1.0 / tanHalf; // n/r

	ret[2][0] = -(farClip + nearClip) / (farClip - nearClip);
	ret[2][3] = -(2 * farClip*nearClip) / (farClip - nearClip);

	ret[3][0] = -1.0;
	
	return ret;
}