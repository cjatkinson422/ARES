#include "GLContext.hpp"


GLContext::GLContext(){
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    this->window = Window::getInstance();

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        glfwTerminate();
    }

}

GLContext* GLContext::instance;
GLContext* GLContext::getInstance(){

    if(!instance)
        instance = new GLContext();
    return instance;

}

GLint GLContext::loadShader(string filename){
    this->shaders[filename] = new Shader(filename);
    return shaders[filename]->getID();
}
Shader* GLContext::getShader(string name){
    return shaders[name];
}