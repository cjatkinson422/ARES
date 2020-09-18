#pragma once
#include "engine/SceneObject.hh"
#include "engine/Shader.hh"


class Planet : public SceneObject{
public:
    Planet();
    Planet(double radius);
    void render();
private:
    Shader shader;

    unsigned int VAO, VBO, EBO;
    unsigned int number_of_vertices;

};