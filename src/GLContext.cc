#include "GLContext.hh"


GLContext::GLContext(){
    glfwInit();
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    this->window = Window::getInstance();

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        glfwTerminate();
        exit(-1);
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