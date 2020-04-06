#pragma once
#include <iostream>
#include "SceneObject.hh"

class HUD : public SceneObject{
public:
    HUD();

    void draw();
private:

    unsigned int VBO;
    unsigned int VAO;
    unsigned int EBO;

    size_t number_of_vertices;

};