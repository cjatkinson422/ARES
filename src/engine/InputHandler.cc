#include <glad/glad.h> 
#include <GLFW/glfw3.h>
#include <iostream>
#include "engine/InputHandler.hh"
#include "engine/Window.hh"


GLdouble InputHandler::cursor_x;
GLdouble InputHandler::cursor_y;

InputHandler::InputHandler(){
    /* Singleton state machine class constructor of the InputHandler class
     * Designed to handle keyboard and mouse input 
    */

    //glfwSetInputMode(Window::getGLFWwindow(), GLFW_CURSOR, GLFW_CURSOR_DISABLED); 

    GLdouble x,y;
    glfwGetCursorPos(Window::getGLFWwindow(), &x,&y);
    cursor_x = x - Window::getWidth()/2;
    cursor_y = y - Window::getHeight()/2;

    glfwSetScrollCallback(Window::getGLFWwindow(), InputHandler::GLFWScrollCallback);
    //glfwSetCursorPos(Window::getGLFWwindow(),cursor_x,cursor_y);
    glfwSetCursorPosCallback(Window::getGLFWwindow(), InputHandler::GLFWCursorCallback);
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
void InputHandler::GLFWCursorCallback(GLFWwindow* window, GLdouble x_position, GLdouble y_position){
    if(InputHandler::instance->CURSOR_callback) InputHandler::instance->CURSOR_callback(x_position-Window::getWidth()/2.0, y_position-Window::getHeight()/2.0);
    cursor_x = x_position - Window::getWidth()/2.0;
    cursor_y = y_position - Window::getHeight()/2.0;;
}


void InputHandler::processInput(const double& delta_time)
{
    if(CURSOR_TICK_callback)CURSOR_TICK_callback(delta_time, cursor_x, cursor_y);

    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS && (ESC_callback)) ESC_callback(delta_time);
    if(glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS && (SPACE_callback)) SPACE_callback(delta_time);
    if(glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS && (LSHIFT_callback)) LSHIFT_callback(delta_time);

    if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS && (A_callback)) A_callback(delta_time);
    if(glfwGetKey(window, GLFW_KEY_B) == GLFW_PRESS && (B_callback)) B_callback(delta_time);
    if(glfwGetKey(window, GLFW_KEY_C) == GLFW_PRESS && (C_callback)) C_callback(delta_time);
    if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS && (D_callback)) D_callback(delta_time);
    if(glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS && (E_callback)) E_callback(delta_time);
    if(glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS && (F_callback)) F_callback(delta_time);
    if(glfwGetKey(window, GLFW_KEY_G) == GLFW_PRESS && (G_callback)) G_callback(delta_time);
    if(glfwGetKey(window, GLFW_KEY_H) == GLFW_PRESS && (H_callback)) H_callback(delta_time);
    if(glfwGetKey(window, GLFW_KEY_I) == GLFW_PRESS && (I_callback)) I_callback(delta_time);
    if(glfwGetKey(window, GLFW_KEY_J) == GLFW_PRESS && (J_callback)) J_callback(delta_time);
    if(glfwGetKey(window, GLFW_KEY_K) == GLFW_PRESS && (K_callback)) K_callback(delta_time);
    if(glfwGetKey(window, GLFW_KEY_L) == GLFW_PRESS && (L_callback)) L_callback(delta_time);
    if(glfwGetKey(window, GLFW_KEY_M) == GLFW_PRESS && (M_callback)) M_callback(delta_time);
    if(glfwGetKey(window, GLFW_KEY_N) == GLFW_PRESS && (N_callback)) N_callback(delta_time);
    if(glfwGetKey(window, GLFW_KEY_O) == GLFW_PRESS && (O_callback)) O_callback(delta_time);
    if(glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS && (P_callback)) P_callback(delta_time);
    if(glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS && (Q_callback)) Q_callback(delta_time);
    if(glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS && (R_callback)) R_callback(delta_time);
    if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS && (S_callback)) S_callback(delta_time);
    if(glfwGetKey(window, GLFW_KEY_T) == GLFW_PRESS && (T_callback)) T_callback(delta_time);
    if(glfwGetKey(window, GLFW_KEY_U) == GLFW_PRESS && (U_callback)) U_callback(delta_time);
    if(glfwGetKey(window, GLFW_KEY_V) == GLFW_PRESS && (V_callback)) V_callback(delta_time);
    if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS && (W_callback)) W_callback(delta_time);
    if(glfwGetKey(window, GLFW_KEY_X) == GLFW_PRESS && (X_callback)) X_callback(delta_time);
    if(glfwGetKey(window, GLFW_KEY_Y) == GLFW_PRESS && (Y_callback)) Y_callback(delta_time);
    if(glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS && (Z_callback)) Z_callback(delta_time);
    
}

void InputHandler::setWindow(GLFWwindow* window){
    /* Sets the window instance of the InputHandler singleton
     * that the inputs are checked in.
    */ 
    this->window = window;
}


const GLdouble& InputHandler::getCursorX(){
    return cursor_x;
}
const GLdouble& InputHandler::getCursorY(){
    return cursor_y;
}

void InputHandler::setCursorPos(GLdouble xpos, GLdouble ypos){
    cursor_x = xpos;
    cursor_y = ypos;
    glfwSetCursorPos(Window::getGLFWwindow(), xpos+Window::getWidth()/2.0, ypos+Window::getHeight()/2.0);
}