#include "interface/HUD.hh"

#include "engine/ObjLoad.hh"
#include "engine/Logger.hh"

#include <glad/glad.h>

HUD::HUD(){
    hud_shader = Shader::HUD;
    hud_texture = TextureHandler::HUD_1;

    float vertices[] = {
        -0.1f, -0.1f, -0.1f, 0.0f, 0.0f,
         0.1f, -0.1f, -0.1f, 1.0f, 0.0f,
         0.1f,  0.1f, -0.1f, 1.0f, 1.0f,
        -0.1f, -0.1f, -0.1f, 0.0f, 0.0f,
         0.1f,  0.1f, -0.1f, 1.0f, 1.0f,
        -0.1f,  0.1f, -0.1f, 0.0f, 1.0f

    }; 
    unsigned int indices[] = {
        0, 1, 2, // first triangle
        3, 4, 5  // second triangle
    };


    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3*sizeof(float)));
    glEnableVertexAttribArray(1);

    number_of_vertices = sizeof(indices) / sizeof(unsigned int);

    hud_shader.setUniform1f("x", 0.0);
    hud_shader.setUniform1f("y", 0.0);
    hud_shader.setUniform1f("aspect", 1.0);

}

void HUD::render(){
    //Logger::println("drawing hud");
    hud_texture.bind();
    hud_shader.use();
    glDepthMask(GL_FALSE);  
    glBindVertexArray(VAO);
    glPolygonMode ( GL_FRONT_AND_BACK, GL_FILL ) ;
    glDrawElements(GL_TRIANGLES, number_of_vertices, GL_UNSIGNED_INT, 0);
    glDepthMask(GL_TRUE);  
}