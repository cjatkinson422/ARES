

#include "HUD.hh"
#include "ObjLoad.hh"
#include <glad/glad.h>
#include "Logger.hh"
#include "GLContext.hh"

HUD::HUD(){


    float vertices[] = {
        -0.1f, -0.1f, -0.1f,
         0.1f, -0.1f, -0.1f,
         0.1f,  0.1f, -0.1f,
        -0.1f, -0.1f, -0.1f,
         0.1f,  0.1f, -0.1f,
        -0.1f,  0.1f, -0.1f

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
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    number_of_vertices = sizeof(indices);

    GLContext::getInstance()->loadShader("hud");
    GLContext::getInstance()->getShader("hud")->setUniform1f("x", 0.0);
    GLContext::getInstance()->getShader("hud")->setUniform1f("y", 0.0);

    GLContext::getInstance()->getShader("hud")->setUniform1f("aspect", 1.0);

}

void HUD::draw(){
    GLContext::getInstance()->getShader("hud")->use();
    glBindVertexArray(VAO);
    glPolygonMode ( GL_FRONT_AND_BACK, GL_FILL ) ;
    glDrawElements(GL_TRIANGLES, number_of_vertices, GL_UNSIGNED_INT, 0);
}