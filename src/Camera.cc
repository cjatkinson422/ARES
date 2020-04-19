#include "Camera.hh"
#include "InputHandler.hh"
#include <functional>
#include "Config.hh"
#include "Window.hh"
#include "Config.hh"
#include "GLContext.hh"
#include "Logger.hh"

Camera::Camera(){
	Config::getInstance()->getValue("fovy", this->fovy);
	Config::getInstance()->getValue("near_clip", this->near_clip);
	Config::getInstance()->getValue("far_clip", this->far_clip);

	this->width = Window::getWidth();
	this->height = Window::getHeight();

	this->aspect = (double)width / (double)height;
	this->updateProjectionMatrix();


	// TODO: NEEDS TO BE REMOVED ONCE HUD CLASS IS IMPROVED
	Shader::HUD.setUniform1f("aspect", float(aspect));

}

void Camera::windowResizeCallback(GLint height, GLint width){
	this->width = width;
	this->height = height;

	this->aspect = width/height;
	Shader::HUD.setUniform1f("aspect", float(aspect));
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

    Shader::static_textured.setUniformMat4("projection", getProjectionMatrix());
    Shader::star.setUniformMat4("projection", getProjectionMatrix());
	
}

mat4& Camera::getProjectionMatrix(){
	return projection_matrix; 
}
void Camera::use(){
    Window::getInstance()->set_RESIZE_callback([this](GLint height, GLint width){this->windowResizeCallback(height, width);});
    InputHandler::getInstance()->set_SCROLL_callback([this](GLdouble scroll_x, GLdouble scroll_y){this->scrollCallback(scroll_x, scroll_y);});
}

void Camera::draw(const double& delta_time, Scene& scene){
	if(parent_obj){
		// Pass it itself to signal this is the entry point to the draw tree.
		parent_obj->draw(-local_position, local_attitude.conj(), delta_time, scene, parent_obj);
	}
	else{
		Logger::println("ERROR:: Attempting to enter the draw tree with an empty parent.");
		exit(0);
	}
	
}