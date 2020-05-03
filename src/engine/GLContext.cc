#include "engine/GLContext.hh"
#include "engine/Logger.hh"

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

    glEnable(GL_BLEND);// you enable blending function
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

}

GLContext* GLContext::instance;
GLContext* GLContext::getInstance(){

    if(!instance)
        instance = new GLContext();
    return instance;

}
