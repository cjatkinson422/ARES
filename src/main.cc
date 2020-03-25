#include <iostream>
#include "GLContext.hh"
#include "InputHandler.hh"
#include "Player.hh"
#include "Camera.hh"
#include "Window.hh"
#include <functional>
#include <algorithm>

float vertices[] = {
    -1.0f, -1.0f, 0.0f,
     1.0f, -1.0f, 0.0f,
     1.0f,  1.0f, 0.0f,

    -1.0f, -1.0f, 0.0f,
     1.0f,  1.0f, 0.0f,
    -1.0f,  1.0f, 0.0f
}; 





int main()
{
    GLContext* context = GLContext::getInstance();
    Window* window = Window::getInstance();
    Camera* cam = Camera::getInstance();
    InputHandler* input_handler = InputHandler::getInstance();
    PlayerController player_controller = PlayerController();
    context->loadShader("julia");
    context->getShader("julia")->use();


    unsigned int VBO;
    glGenBuffers(1, &VBO); 
    glBindBuffer(GL_ARRAY_BUFFER, VBO);  
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    unsigned int VAO;
    glGenVertexArrays(1, &VAO); 

    
    
    // 1. bind Vertex Array Object
    glBindVertexArray(VAO);
    // 2. copy our vertices array in a buffer for OpenGL to use
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);  

    // 0. copy our vertices array in a buffer for OpenGL to use
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    
    while(!window->shouldClose())
    {
        // input
        input_handler->processInput();

        // rendering commands here
        
        glClearColor(248.0f/256.0f, 201.0f/256.0f, 95.0f/256.0f,1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 6);

        // check and call events and swap the buffers
        glfwPollEvents();
        glfwSwapBuffers(window->getGLFWwindow());  
    }

    glfwTerminate();
    return 0;
}