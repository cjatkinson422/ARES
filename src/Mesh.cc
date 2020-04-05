#include "Mesh.hh"
#include "ObjLoad.hh"
#include <glad/glad.h>
#include "Logger.hh"
#include "GLContext.hh"

Mesh::Mesh(){};

Mesh::Mesh(string filename){

    bool successful_load;

    std::vector<std::array<float,8>> vertex_data;
    std::vector<unsigned int> index_data;

    successful_load = loadObj(filename, vertex_data, index_data);

    if(successful_load){
        Logger::println("Loaded obj file " + filename);
    }
    else{
        Logger::println("Failed to load obj file " + filename);
    }

    float vertices[] = {
        // positions          // colors           // texture coords
         0.5f,  0.5f, 1.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f, // top right
         0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f, // bottom right
        -0.5f, -0.5f, -1.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f, // bottom left
        -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f  // top left 
    };
    unsigned int indices[] = {
        0, 1, 3, // first triangle
        1, 2, 3  // second triangle
    };


    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertex_data.size()*sizeof(vertex_data[0]), &vertex_data.data()[0], GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, index_data.size()*sizeof(unsigned long), index_data.data(), GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // normal attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    // texture coord attribute
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);

    number_of_vertices = index_data.size();

    vertex_data.clear();
    index_data.clear();
}

void Mesh::draw(){
    GLContext::getInstance()->getShader("julia")->use();
    glBindVertexArray(VAO);
    glPolygonMode ( GL_FRONT_AND_BACK, GL_LINE ) ;
    glDrawElements(GL_TRIANGLES, number_of_vertices, GL_UNSIGNED_INT, 0);
}