#include <iostream>
#include "GLContext.hpp"
#include "InputHandler.hpp"
#include "Camera.hpp"
#include "Window.hpp"

float vertices[] = {
    -1.0f, -1.0f, 0.0f,
     1.0f, -1.0f, 0.0f,
     1.0f,  1.0f, 0.0f,

    -1.0f, -1.0f, 0.0f,
     1.0f,  1.0f, 0.0f,
    -1.0f,  1.0f, 0.0f
}; 


const GLfloat gold = 1.61803398875;
GLfloat cr = (gold-2.0);
GLfloat ci = (gold-1.0);



int main()
{
    GLContext* context = GLContext::getInstance();
    Window* window = Window::getInstance();
    Camera* cam = Camera::getInstance();
    InputHandler* input_handler = InputHandler::getInstance();
    context->loadShader("julia");
    context->getShader("julia")->use();
    context->getShader("julia")->setUniform1f("ci", ci);
    context->getShader("julia")->setUniform1f("cr",cr);
    context->getShader("julia")->setUniform1f("scale",1.0f);

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