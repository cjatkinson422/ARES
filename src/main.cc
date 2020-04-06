#include <iostream>
#include "GLContext.hh"
#include "InputHandler.hh"
#include "TextureHandler.hh"
#include "Player.hh"
#include "Camera.hh"
#include "Window.hh"
#include <functional>
#include <algorithm>

#include "LandingPad.hh"
#include "Scene.hh"
#include "Star.hh"


int main()
{
    GLContext* context = GLContext::getInstance();
    Window* window = Window::getInstance();
    TextureHandler* texture_handler = TextureHandler::getInstance();
    context->loadShader("static_textured");
    context->loadShader("star");
    context->loadShader("hud");

    InputHandler* input_handler = InputHandler::getInstance();
    Player player = Player();

    MeshRenderer ship = MeshRenderer("data/models/ship.obj", context->getShader("star"));
    ship.set_render_mode(GL_LINE);

    Star sol = Star();

    Scene scene = Scene();
    LandingPad landing_pad = LandingPad();

    scene.add_scene_object(&landing_pad);
    scene.add_scene_object(&ship);
    scene.add_scene_object(&player);
    scene.add_scene_object(&sol);



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

        scene.render(&player.get_camera());

        // check and call events and swap the buffers
        glfwPollEvents();
        glfwSwapBuffers(window->getGLFWwindow());  

        // Update the time
        loop_time = glfwGetTime();
    }

    glfwTerminate();
    return 0;
}