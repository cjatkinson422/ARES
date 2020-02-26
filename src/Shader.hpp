#pragma once
#include <glad/glad.h> 
#include <GLFW/glfw3.h>
#include <string>
#include <GNClib/linalg.hpp>

using std::string;

class Shader{
private:
    GLuint programID;
public:
    Shader(string filename);
    void use();
    GLint getID();

    void setUniformV3(const char* uniform_name, vec3& v);
    void setUniform1f(const char* uniform_name, float f);
    void setUniformMat4(const char* uniform_name, mat4& mat);
};