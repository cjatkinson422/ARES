#pragma once
#include <glad/glad.h> 
#include <GLFW/glfw3.h>
#include <map>
#include "engine/Window.hh"
#include "engine/Shader.hh"

class GLContext
{
private:
    GLContext(/* args */);
    static GLContext* instance;
    Window* window;

    std::map<string, Shader*> shaders;
public:
    static GLContext* getInstance();
};

