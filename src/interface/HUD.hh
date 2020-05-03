#pragma once
#include <iostream>
#include "engine/SceneObject.hh"
#include "engine/Shader.hh"
#include "engine/TextureHandler.hh"

class HUD : public SceneObject{
public:
    HUD();

    void render();
private:

    unsigned int VBO;
    unsigned int VAO;
    unsigned int EBO;

    size_t number_of_vertices;

    Texture hud_texture;
    Shader hud_shader;
};