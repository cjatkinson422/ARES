#pragma once
#include <iostream>
#include "SceneObject.hh"
#include "Shader.hh"

class HUD : public SceneObject{
public:
    HUD();

    void render();
private:

    unsigned int VBO;
    unsigned int VAO;
    unsigned int EBO;

    size_t number_of_vertices;

    Shader hud_shader = Shader::HUD;
};