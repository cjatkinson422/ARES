#pragma once
#include <string>
#include <glad/glad.h>
#include "SceneObject.hh"
#include "Shader.hh"

class MeshRenderer : public SceneObject
{
public:
    MeshRenderer(std::string filename, Shader* shader_init);
    MeshRenderer(std::string filename);
    MeshRenderer();

    void draw(Shader* shader, );
    void set_render_mode(GLenum mode);
private:
    unsigned int VBO;
    unsigned int VAO;
    unsigned int EBO;

    size_t number_of_vertices;

    GLuint64 render_mode;

    Shader* shader = NULL; 
};