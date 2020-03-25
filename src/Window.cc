#include "Window.hh"
#include "Camera.hh"
#include "InputHandler.hh"


GLFWwindow* Window::glfw_window;
Window* Window::instance;

Window::Window(){
    /* Singleton class constructor of the Window class
     * Designed to wrap the GLFW window class and callbacks 
    */
    glfw_window = glfwCreateWindow(1800, 1400, "ARES", NULL, NULL);
    if (glfw_window == NULL)
    {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        exit(-1);
    }
    glfwMakeContextCurrent(glfw_window);
    InputHandler* input_handler = InputHandler::getInstance();
    input_handler->setWindow(glfw_window);
}

Window* Window::getInstance(){
    /* Returns the singleton instance of the Window class
    */
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

