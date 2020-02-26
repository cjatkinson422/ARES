#pragma once
#include <glad/glad.h> 
#include <GLFW/glfw3.h>
#include <map>
#include "Window.hpp"
#include "Shader.hpp"

class GLContext
{
private:
    GLContext(/* args */);
    static GLContext* instance;
    Window* window;

    std::map<string, Shader*> shaders;
public:
    static GLContext* getInstance();
    GLint loadShader(string filename);
    Shader* getShader(string name);
};

