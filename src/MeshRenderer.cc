#include "MeshRenderer.hh"
#include "ObjLoad.hh"
#include "Logger.hh"
#include "GLContext.hh"

MeshRenderer::MeshRenderer(){};

MeshRenderer::MeshRenderer(string filename){

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

    this->set_render_mode(GL_FILL);
}
MeshRenderer::MeshRenderer(std::string filename, Shader* shader_init) : MeshRenderer::MeshRenderer(filename){
    this->shader = shader_init;
}

void MeshRenderer::draw(){
    if(shader){
        shader->use();
        glBindVertexArray(VAO);
        glPolygonMode ( GL_FRONT_AND_BACK, render_mode ) ;
        glDrawElements(GL_TRIANGLES, number_of_vertices, GL_UNSIGNED_INT, 0);
    }
    else
        Logger::println("Attempting to draw object with no shader");
}

void MeshRenderer::set_render_mode(GLenum mode){
    this->render_mode = mode;
}