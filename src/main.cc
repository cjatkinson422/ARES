#include <iostream>
#include "GLContext.hh"
#include "InputHandler.hh"
#include "Player.hh"
#include "Camera.hh"
#include "Window.hh"
#include <functional>
#include <algorithm>






int main()
{   

    GLContext* context = GLContext::getInstance();
    Window* window = Window::getInstance();

    InputHandler* input_handler = InputHandler::getInstance();
    Player player = Player();
    context->loadShader("julia");
    context->getShader("julia")->use();

    Mesh sphere = Mesh("data/models/falcon.obj");


    double loop_time = glfwGetTime();
    double old_time = glfwGetTime();
    while(!window->shouldClose())
    {
        // Get the time since the last frame
        double delta_time = loop_time - old_time;
        old_time = glfwGetTime();

        // Process the mouse and keyboard input
        input_handler->processInput(delta_time);
        // Tick the player forward in time
        player.tick(delta_time);
        

        // rendering commands here
        
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


        glEnable(GL_DEPTH_TEST);  

        sphere.draw();
        player.draw();
        // check and call events and swap the buffers
        glfwPollEvents();
        glfwSwapBuffers(window->getGLFWwindow());  

        // Update the time
        loop_time = glfwGetTime();
    }

    glfwTerminate();
    return 0;
}