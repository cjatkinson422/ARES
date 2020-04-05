#pragma once
#include <string>

class Mesh
{
public:
    Mesh(std::string filename);
    Mesh();

    void draw();
private:
    unsigned int VBO;
    unsigned int VAO;
    unsigned int EBO;

    size_t number_of_vertices;
};