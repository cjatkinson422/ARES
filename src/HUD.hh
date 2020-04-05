#pragma once
#include <iostream>

class HUD{
public:
    HUD();

    void draw();
private:

    unsigned int VBO;
    unsigned int VAO;
    unsigned int EBO;

    size_t number_of_vertices;

};