#include "Window.hh"
#include "Camera.hh"
#include "InputHandler.hh"
#include "Config.hh"
#include "Logger.hh"

GLFWwindow* Window::glfw_window;
Window* Window::instance;

GLint Window::width = 0;
GLint Window::height = 0;

Window::Window(){
    // Get an instance of the config reader
    Config* configs = Config::getInstance();

    Logger::println("Initializing Window");

    // read values from configs
    configs->getValue("window_width", Window::width);
    configs->getValue("window_height", Window::height);

    // Create the glfw window object
    glfw_window = glfwCreateWindow(width, height, "ARES", NULL, NULL);

    // Verify that the window opened properly
    if (glfw_window == NULL)
    {
        Logger::print("Failed to create GLFW window of size");
        glfwTerminate();
        exit(-1);
    }

    // Set this glfw window object as the primary one
    glfwMakeContextCurrent(glfw_window);
    
    // Tell the input handler to use input from this glfw window.
    InputHandler::getInstance()->setWindow(glfw_window);
    glfwSetFramebufferSizeCallback(Window::getGLFWwindow(), Window::GLFWFramebufferResizeCallback);
    glfwSetCursorPos(Window::glfw_window, Window::width/2.0 + 30, Window::height/2.0);
}

Window* Window::getInstance(){
    if(!instance)
       instance = new Window();
    return instance;
    
}

void Window::close(){
    glfwSetWindowShouldClose(glfw_window,1);
}
bool Window::shouldClose(){
    return glfwWindowShouldClose(glfw_window);
}


void Window::GLFWFramebufferResizeCallback(GLFWwindow* window, GLint width, GLint height){
    Window::width = width;
    Window::height = height;
    glViewport(0.0,0.0,width,height);
    if(Window::instance->RESIZE_callback) Window::instance->RESIZE_callback(width,height);
}

GLint Window::getWidth(){
    return Window::width;
}
GLint Window::getHeight(){
    return Window::height;
}