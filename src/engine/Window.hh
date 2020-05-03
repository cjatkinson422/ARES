#pragma once
#include <glad/glad.h> 
#include <GLFW/glfw3.h>
#include <functional>

typedef std::function<void(GLint, GLint)> WINDOW_RESIZE_CALLBACK;

class Window
{
private:
    /* Singleton class constructor of the Window class
     * Designed to wrap the GLFW window class and callbacks 
    */
    Window();

    // width and height of the window in pixels
    static GLint width;
    static GLint height;

    // static location to hold instance
    static Window* instance;
    // static location to store the glfw window object
    static GLFWwindow* glfw_window;

    WINDOW_RESIZE_CALLBACK RESIZE_callback;

public:

    // Returns the singleton instance of the Window class
    static Window* getInstance();
    static GLFWwindow* getGLFWwindow(){return glfw_window;}

    void set_RESIZE_callback(WINDOW_RESIZE_CALLBACK callback){this->RESIZE_callback = callback;}
    static void GLFWFramebufferResizeCallback(GLFWwindow* windw, GLint width, GLint height);

    static GLint getWidth();
    static GLint getHeight();

    bool shouldClose();
    void close();
};

