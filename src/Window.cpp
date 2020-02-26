#include "Window.hpp"
#include "Camera.hpp"
#include "InputHandler.hpp"


GLFWwindow* Window::glfw_window;
Window* Window::instance;

Window::Window(/* args */){
    /* Singleton class constructor of the Window class
     * Designed to wrap the GLFW window class and callbacks 
    */
    glfw_window = glfwCreateWindow(1800, 1400, "ARES", NULL, NULL);
    if (glfw_window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
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

