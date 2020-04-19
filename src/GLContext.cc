#include "GLContext.hh"
#include "Logger.hh"

GLContext::GLContext(){
    Logger::println("Initializing GLFW context");

    glfwInit();
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    this->window = Window::getInstance();

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        Logger::println("Failed to initialize GLAD. Exiting.");
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
