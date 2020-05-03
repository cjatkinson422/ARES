#pragma once
#include <glad/glad.h> 
#include <GLFW/glfw3.h>
#include <string>
#include <GNClib/linalg.hh>

using std::string;

class Shader{
private:
    GLuint programID;
    Shader(string filename);
public:
    Shader(){programID = 0;}

    // TODO create a static class that is a friend to things that need initializing
    static void initialize_shaders();
    GLint getID();
    void use();

    void setUniformV3(const char* uniform_name, const vec3& v);
    void setUniform1f(const char* uniform_name, float f);
    void setUniformMat4(const char* uniform_name, const mat4& mat);

    static Shader star;
    static Shader static_textured;
    static Shader HUD;

};