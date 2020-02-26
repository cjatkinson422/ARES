#include "Shader.hpp"
#include <fstream>
#include <streambuf>
#include <sstream>
#include <iostream>

Shader::Shader(string filename){
    std::ifstream tv("shaders/"+filename+".vert");
    std::stringstream vertbuffer;
    vertbuffer << tv.rdbuf();
    std::string vertString = vertbuffer.str();
    const char* vertChar = vertString.c_str();

    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);

    glShaderSource(vertexShader, 1, &vertChar, NULL);
    glCompileShader(vertexShader);

    int  success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

    if(!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    std::ifstream tf("shaders/"+filename+".frag");
    std::stringstream fragbuffer;
    fragbuffer << tf.rdbuf();
    std::string fragString = fragbuffer.str();
    const char* fragChar = fragString.c_str();
    
    
    unsigned int fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragChar, NULL);
    glCompileShader(fragmentShader);

    programID = glCreateProgram();

    glAttachShader(programID, vertexShader);
    glAttachShader(programID, fragmentShader);
    glLinkProgram(programID);

    glGetProgramiv(programID, GL_LINK_STATUS, &success);
    if(!success) {
        glGetProgramInfoLog(programID, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader); 
}

void Shader::use(){
    glUseProgram(programID);
}
GLint Shader::getID(){
    return this->programID;
}

void Shader::setUniformV3(const char* uniform_name, vec3& v){
    this->use();
    glUniform3d(glGetUniformLocation(programID,uniform_name), v.x, v.y, v.z);
}

void Shader::setUniform1f(const char* uniform_name, float f){
    this->use();
    glUniform1f(glGetUniformLocation(programID,uniform_name), f);
}
void Shader::setUniformMat4(const char* uniform_name, mat4& mat){
    this->use();
    glUniformMatrix4fv(glGetUniformLocation(programID,uniform_name), 16*sizeof(GLfloat), false, mat.)
}