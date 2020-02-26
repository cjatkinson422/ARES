#pragma once
#include <glad/glad.h> 
#include <GLFW/glfw3.h>


class Window
{
private:
    /* data */
    Window();
    static Window* instance;
    static GLFWwindow* glfw_window;
public:

    static Window* getInstance();
    static GLFWwindow* getGLFWwindow(){return glfw_window;}

    bool shouldClose();
    void close();
};

