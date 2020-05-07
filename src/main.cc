#include <iostream>
#include "engine/GLContext.hh"
#include "engine/InputHandler.hh"
#include "engine/TextureHandler.hh"
#include "engine/Shader.hh"
#include "objects/Player.hh"
#include "objects/Camera.hh"
#include "engine/Window.hh"
#include <functional>
#include <algorithm>

#include "usr/LandingPad.hh"
#include "engine/Scene.hh"
#include "usr/Star.hh"
#include "usr/Planet.hh"


int main()
{
    GLContext* context = GLContext::getInstance();
    Window* window = Window::getInstance();
    TextureHandler* texture_handler = TextureHandler::getInstance();
    Shader::initialize_shaders();

    InputHandler* input_handler = InputHandler::getInstance();
    Scene scene = Scene();
    Player player = Player();
    scene.bind_camera(&player.get_camera());



    Star sol = Star(vec3(-5.0,30.0,-50.0), quaternion());
    LandingPad landing_pad = LandingPad();
    Planet earth = Planet();
    
    earth.bind_to_parent(&landing_pad, false);
    sol.bind_to_parent(&landing_pad, false); // TODO try true
    player.bind_to_parent(&landing_pad, false);


    Logger::println("Entering main loop.");
    double loop_time = glfwGetTime();
    double old_time = glfwGetTime();
    while(!window->shouldClose())
    {
        // Get the time since the last frame
        double delta_time = loop_time - old_time;
        old_time = glfwGetTime();
        // Process the mouse and keyboard input
        input_handler->processInput(delta_time);
        

        // rendering commands here
        
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


        glEnable(GL_DEPTH_TEST);  

        scene.draw(delta_time);

        // check and call events and swap the buffers
        glfwPollEvents();
        glfwSwapBuffers(window->getGLFWwindow());  

        // Update the time
        loop_time = glfwGetTime();
    }

    glfwTerminate();
    return 0;
}