#include "Camera.hh"
#include "InputHandler.hh"
#include <functional>
#include "Config.hh"
#include "Window.hh"
#include "Config.hh"

Camera::Camera(){
	Config::getInstance()->getValue("fovy", this->fovy);
	Config::getInstance()->getValue("near_clip", this->near_clip);
	Config::getInstance()->getValue("far_clip", this->far_clip);

	this->width = Window::getWidth();
	this->height = Window::getHeight();

	this->aspect = (double)width / (double)height;
	this->updateProjectionMatrix();
	this->updateViewMatrix();

}

void Camera::windowResizeCallback(GLint height, GLint width){
	this->width = width;
	this->height = height;

	this->aspect = width/height;
	this->updateProjectionMatrix();
}
void Camera::scrollCallback(GLdouble xoffset, GLdouble yoffset){

}

void Camera::updateProjectionMatrix() {

	
	double uh = 1.0 / (tan( fovy/2.0 ));
	double uw = uh/aspect;

	projection_matrix[0][0] = uw;
	projection_matrix[1][1] = uh;
	projection_matrix[2][2] = -far_clip / (far_clip-near_clip);
	projection_matrix[3][2] = -1.0;
	projection_matrix[2][3] = -far_clip*near_clip / (far_clip-near_clip);

	projection_matrix = projection_matrix;
	this->view_projection_matrix = projection_matrix* view_matrix;
	
}

void Camera::updateViewMatrix(){
	view_matrix = mat4::eye();
	view_matrix.x.w = -position.x;
	view_matrix.y.w = -position.y;
	view_matrix.z.w = -position.z;

	view_matrix = rotation.toMat3().expand().transpose() * view_matrix;


	this->view_projection_matrix = projection_matrix* view_matrix;
}

mat4& Camera::getViewProjectionMatrix(){
	return this->view_projection_matrix; 
}
void Camera::use(){
    Window::getInstance()->set_RESIZE_callback([this](GLint height, GLint width){this->windowResizeCallback(height, width);});
    InputHandler::getInstance()->set_SCROLL_callback([this](GLdouble scroll_x, GLdouble scroll_y){this->scrollCallback(scroll_x, scroll_y);});
}