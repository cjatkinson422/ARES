#include <glad/glad.h> 
#include <GLFW/glfw3.h>
#include <iostream>
#include "InputHandler.hh"
#include "Window.hh"


InputHandler::InputHandler(){
    /* Singleton state machine class constructor of the InputHandler class
     * Designed to handle keyboard and mouse input 
    */
    glfwSetFramebufferSizeCallback(Window::getGLFWwindow(), InputHandler::GLFWFramebufferResizeCallback);
    glfwSetScrollCallback(Window::getGLFWwindow(), InputHandler::GLFWScrollCallback);
}

InputHandler* InputHandler::instance;
InputHandler* InputHandler::getInstance(){
    /* Returns the singleton instance of the InputHandler class
    */
    
    if(!instance)
        instance = new InputHandler();
    return instance;
    
}

void InputHandler::GLFWScrollCallback(GLFWwindow* window, GLdouble xoffset, GLdouble yoffset){
    if(InputHandler::instance->SCROLL_callback) InputHandler::instance->SCROLL_callback(xoffset,yoffset);
}
void InputHandler::GLFWFramebufferResizeCallback(GLFWwindow* window, GLint width, GLint height){
    glViewport(0.0,0.0,width,height);
    if(InputHandler::instance->RESIZE_callback) InputHandler::instance->RESIZE_callback(width,height);
}

void InputHandler::processInput()
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS && (ESC_callback)) ESC_callback();
    if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS && (A_callback)) A_callback();
    if(glfwGetKey(window, GLFW_KEY_B) == GLFW_PRESS && (B_callback)) B_callback();
    if(glfwGetKey(window, GLFW_KEY_C) == GLFW_PRESS && (C_callback)) C_callback();
    if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS && (D_callback)) D_callback();
    if(glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS && (E_callback)) E_callback();
    if(glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS && (F_callback)) F_callback();
    if(glfwGetKey(window, GLFW_KEY_G) == GLFW_PRESS && (G_callback)) G_callback();
    if(glfwGetKey(window, GLFW_KEY_H) == GLFW_PRESS && (H_callback)) H_callback();
    if(glfwGetKey(window, GLFW_KEY_I) == GLFW_PRESS && (I_callback)) I_callback();
    if(glfwGetKey(window, GLFW_KEY_J) == GLFW_PRESS && (J_callback)) J_callback();
    if(glfwGetKey(window, GLFW_KEY_K) == GLFW_PRESS && (K_callback)) K_callback();
    if(glfwGetKey(window, GLFW_KEY_L) == GLFW_PRESS && (L_callback)) L_callback();
    if(glfwGetKey(window, GLFW_KEY_M) == GLFW_PRESS && (M_callback)) M_callback();
    if(glfwGetKey(window, GLFW_KEY_N) == GLFW_PRESS && (N_callback)) N_callback();
    if(glfwGetKey(window, GLFW_KEY_O) == GLFW_PRESS && (O_callback)) O_callback();
    if(glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS && (P_callback)) P_callback();
    if(glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS && (Q_callback)) Q_callback();
    if(glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS && (R_callback)) R_callback();
    if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS && (S_callback)) S_callback();
    if(glfwGetKey(window, GLFW_KEY_T) == GLFW_PRESS && (T_callback)) T_callback();
    if(glfwGetKey(window, GLFW_KEY_U) == GLFW_PRESS && (U_callback)) U_callback();
    if(glfwGetKey(window, GLFW_KEY_V) == GLFW_PRESS && (V_callback)) V_callback();
    if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS && (W_callback)) W_callback();
    if(glfwGetKey(window, GLFW_KEY_X) == GLFW_PRESS && (X_callback)) X_callback();
    if(glfwGetKey(window, GLFW_KEY_Y) == GLFW_PRESS && (Y_callback)) Y_callback();
    if(glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS && (Z_callback)) Z_callback();
    
}

void InputHandler::setWindow(GLFWwindow* window){
    /* Sets the window instance of the InputHandler singleton
     * that the inputs are checked in.
    */ 
    this->window = window;
}