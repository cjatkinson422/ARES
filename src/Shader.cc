#include "Shader.hh"
#include <fstream>
#include <streambuf>
#include <sstream>
#include <iostream>
#include "Logger.hh"


Shader Shader::star;
Shader Shader::static_textured;
Shader Shader::julia;
Shader Shader::HUD;

void Shader::initialize_shaders(){
    // TODO read from a config file (build file?)

    star = Shader("star");
    static_textured = Shader("static_textured");
    julia = Shader("julia");
    HUD = Shader("hud");
}

Shader::Shader(string filename){

    Logger::println("Loading shader " + filename);
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
    glUseProgram(programID);

    glAttachShader(programID, vertexShader);
    glAttachShader(programID, fragmentShader);
    glLinkProgram(programID);

    glGetProgramiv(programID, GL_LINK_STATUS, &success);
    if(!success) {
        glGetProgramInfoLog(programID, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    glUniform1i(glGetUniformLocation(programID, "texture0"),  0);
    glUniform1i(glGetUniformLocation(programID, "texture1"),  1);
    glUniform1i(glGetUniformLocation(programID, "texture2"),  2);
    glUniform1i(glGetUniformLocation(programID, "texture3"),  3);
    glUniform1i(glGetUniformLocation(programID, "texture4"),  4);
    glUniform1i(glGetUniformLocation(programID, "texture5"),  5);
    glUniform1i(glGetUniformLocation(programID, "texture6"),  6);
    glUniform1i(glGetUniformLocation(programID, "texture7"),  7);
    glUniform1i(glGetUniformLocation(programID, "texture8"),  8);
    glUniform1i(glGetUniformLocation(programID, "texture9"),  9);
    glUniform1i(glGetUniformLocation(programID, "texture10"), 10);
    glUniform1i(glGetUniformLocation(programID, "texture11"), 11);
    glUniform1i(glGetUniformLocation(programID, "texture12"), 12);
    glUniform1i(glGetUniformLocation(programID, "texture13"), 13);
    glUniform1i(glGetUniformLocation(programID, "texture14"), 14);
    glUniform1i(glGetUniformLocation(programID, "texture15"), 15);

    

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader); 
}

void Shader::use(){
    glUseProgram(programID);
}
GLint Shader::getID(){
    return this->programID;
}

void Shader::setUniformV3(const char* uniform_name, const vec3& v){
    this->use();
    auto vf = v.gl_float_ref();
    glUniform3fv(glGetUniformLocation(programID,uniform_name),1, &vf[0]);
}

void Shader::setUniform1f(const char* uniform_name, float f){
    this->use();
    glUniform1f(glGetUniformLocation(programID,uniform_name), f);
}
void Shader::setUniformMat4(const char* uniform_name, const mat4& mat){
    this->use();
    std::array<float, 16UL> float_ptr = mat.gl_float_ref();
    glUniformMatrix4fv(glGetUniformLocation(programID,uniform_name), 1, true, &float_ptr[0]);
}