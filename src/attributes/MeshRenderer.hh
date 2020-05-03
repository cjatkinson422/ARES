#pragma once
#include <string>
#include <glad/glad.h>
#include "engine/SceneObject.hh"
#include "engine/Shader.hh"

class MeshRenderer
{
public:
    MeshRenderer(std::string filename, Shader shader_init);
    MeshRenderer();

    void render(const mat4& model_matrix);
    void set_render_mode(GLenum mode);
    void set_shader(Shader new_shader);
private:
    MeshRenderer(std::string filename);
    unsigned int VBO;
    unsigned int VAO;
    unsigned int EBO;

    size_t number_of_vertices;

    GLuint64 render_mode;

    Shader shader; 
};