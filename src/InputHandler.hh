#pragma once
#include <glad/glad.h> 
#include <GLFW/glfw3.h>
#include <functional>


#define SHIP_MODE 1


typedef std::function<void(GLdouble)> INPUT_KEY_CALLBACK;
typedef std::function<void(GLdouble, GLdouble)> INPUT_SCROLL_CALLBACK;
typedef std::function<void(GLdouble, GLdouble)> INPUT_CURSOR_CALLBACK;
typedef std::function<void(GLdouble, GLdouble, GLdouble)> INPUT_CURSOR_TICK_CALLBACK;

class InputHandler{
public:
    static InputHandler* getInstance();

    void setWindow(GLFWwindow *window);
    void processInput(const double& delta_time);


    void set_SCROLL_callback(INPUT_SCROLL_CALLBACK callback){this->SCROLL_callback = callback;}
    void set_CURSOR_callback(INPUT_CURSOR_CALLBACK callback){this->CURSOR_callback = callback;}

    void set_CURSOR_TICK_callback (INPUT_CURSOR_TICK_CALLBACK callback){this->CURSOR_TICK_callback = callback;}
    
    void set_ESC_callback(INPUT_KEY_CALLBACK callback){this->ESC_callback = callback;}
    void set_SPACE_callback(INPUT_KEY_CALLBACK callback){this->SPACE_callback = callback;}
    void set_LSHIFT_callback(INPUT_KEY_CALLBACK callback){this->LSHIFT_callback = callback;}

    void set_A_callback(INPUT_KEY_CALLBACK callback){this->A_callback = callback;}
    void set_B_callback(INPUT_KEY_CALLBACK callback){this->B_callback = callback;}
    void set_C_callback(INPUT_KEY_CALLBACK callback){this->C_callback = callback;}
    void set_D_callback(INPUT_KEY_CALLBACK callback){this->D_callback = callback;}
    void set_E_callback(INPUT_KEY_CALLBACK callback){this->E_callback = callback;}
    void set_F_callback(INPUT_KEY_CALLBACK callback){this->F_callback = callback;}
    void set_G_callback(INPUT_KEY_CALLBACK callback){this->G_callback = callback;}
    void set_H_callback(INPUT_KEY_CALLBACK callback){this->H_callback = callback;}
    void set_I_callback(INPUT_KEY_CALLBACK callback){this->I_callback = callback;}
    void set_J_callback(INPUT_KEY_CALLBACK callback){this->J_callback = callback;}
    void set_K_callback(INPUT_KEY_CALLBACK callback){this->K_callback = callback;}
    void set_L_callback(INPUT_KEY_CALLBACK callback){this->L_callback = callback;}
    void set_M_callback(INPUT_KEY_CALLBACK callback){this->M_callback = callback;}
    void set_N_callback(INPUT_KEY_CALLBACK callback){this->N_callback = callback;}
    void set_O_callback(INPUT_KEY_CALLBACK callback){this->O_callback = callback;}
    void set_P_callback(INPUT_KEY_CALLBACK callback){this->P_callback = callback;}
    void set_Q_callback(INPUT_KEY_CALLBACK callback){this->Q_callback = callback;}
    void set_R_callback(INPUT_KEY_CALLBACK callback){this->R_callback = callback;}
    void set_S_callback(INPUT_KEY_CALLBACK callback){this->S_callback = callback;}
    void set_T_callback(INPUT_KEY_CALLBACK callback){this->T_callback = callback;}
    void set_U_callback(INPUT_KEY_CALLBACK callback){this->U_callback = callback;}
    void set_V_callback(INPUT_KEY_CALLBACK callback){this->V_callback = callback;}
    void set_W_callback(INPUT_KEY_CALLBACK callback){this->W_callback = callback;}
    void set_X_callback(INPUT_KEY_CALLBACK callback){this->X_callback = callback;}
    void set_Y_callback(INPUT_KEY_CALLBACK callback){this->Y_callback = callback;}
    void set_Z_callback(INPUT_KEY_CALLBACK callback){this->Z_callback = callback;}

    const GLdouble& getCursorX();
    const GLdouble& getCursorY();
    void setCursorPos(GLdouble, GLdouble);

private:
    static InputHandler* instance;

    InputHandler();
    InputHandler(InputHandler const&);
    InputHandler& operator=(InputHandler const&);

    GLFWwindow* window;
    
    static GLdouble cursor_x;
    static GLdouble cursor_y;

    static void GLFWScrollCallback(GLFWwindow* window, GLdouble xoffset, GLdouble yoffset);
    static void GLFWCursorCallback(GLFWwindow* window, GLdouble xoffset, GLdouble yoffset);


    INPUT_SCROLL_CALLBACK SCROLL_callback;
    INPUT_CURSOR_CALLBACK CURSOR_callback;

    INPUT_CURSOR_TICK_CALLBACK CURSOR_TICK_callback;
    
    INPUT_KEY_CALLBACK ESC_callback;
    INPUT_KEY_CALLBACK LSHIFT_callback;
    INPUT_KEY_CALLBACK SPACE_callback;
    
    INPUT_KEY_CALLBACK A_callback;
    INPUT_KEY_CALLBACK B_callback;
    INPUT_KEY_CALLBACK C_callback;
    INPUT_KEY_CALLBACK D_callback;
    INPUT_KEY_CALLBACK E_callback;
    INPUT_KEY_CALLBACK F_callback;
    INPUT_KEY_CALLBACK G_callback;
    INPUT_KEY_CALLBACK H_callback;
    INPUT_KEY_CALLBACK I_callback;
    INPUT_KEY_CALLBACK J_callback;
    INPUT_KEY_CALLBACK K_callback;
    INPUT_KEY_CALLBACK L_callback;
    INPUT_KEY_CALLBACK M_callback;
    INPUT_KEY_CALLBACK N_callback;
    INPUT_KEY_CALLBACK O_callback;
    INPUT_KEY_CALLBACK P_callback;
    INPUT_KEY_CALLBACK Q_callback;
    INPUT_KEY_CALLBACK R_callback;
    INPUT_KEY_CALLBACK S_callback;
    INPUT_KEY_CALLBACK T_callback;
    INPUT_KEY_CALLBACK U_callback;
    INPUT_KEY_CALLBACK V_callback;
    INPUT_KEY_CALLBACK W_callback;
    INPUT_KEY_CALLBACK X_callback;
    INPUT_KEY_CALLBACK Y_callback;
    INPUT_KEY_CALLBACK Z_callback;

};

