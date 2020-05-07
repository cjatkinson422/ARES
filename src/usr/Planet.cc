#include "usr/Planet.hh"
#include <glad/glad.h>

Planet::Planet(){
    model_matrix = mat4::eye();
    shader = Shader::solid_color;

    local_position = vec3(0.0,5.0,0.0);
    
    // Icosahedron constants
    const float A = 0.525731112119133606f;
    const float B = 0.850650808352039932f;
    const float C = 0.000000000000000000f;

    float vertices[] = {
        -A, C, B,
         A, C, B,
        -A, C,-B,
         A, C,-B,
         C, B, A,
         C, B,-A,
         C,-B, A,
         C,-B,-A,
         B, A, C,
        -B, A, C,
         B,-A, C,
        -B,-A, C
    };

    unsigned int indices[] ={
    0,4,1,0,9,4,9,5,4,4,5,8,4,8,1,
    8,10,1,8,3,10,5,3,8,5,2,3,2,7,3,
    7,10,3,7,6,10,7,11,6,11,0,6,0,1,6,
    6,1,10,9,0,11,9,11,2,9,2,5,7,2,11
    };



    // now reserve the memory for the full planet object. 
    // it must be static throughout all LOD layers
    //glBindBuffer(GL_ARRAY_BUFFER, VBO);
    //glBufferData(GL_ARRAY_BUFFER, 10000, NULL, GL_DYNAMIC_DRAW);

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

    number_of_vertices = sizeof(indices) / sizeof(unsigned int);
    Logger::println(number_of_vertices);

}

void Planet::render(){
    shader.use();
    shader.setUniformMat4("model_matrix", model_matrix);
    glBindVertexArray(VAO);
    glPolygonMode ( GL_FRONT_AND_BACK, GL_LINE ) ;
    glDrawElements(GL_TRIANGLES, 60, GL_UNSIGNED_INT, 0);

}