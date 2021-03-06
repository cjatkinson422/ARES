#include "attributes/MeshRenderer.hh"
#include "engine/ObjLoad.hh"
#include "engine/Logger.hh"
#include "engine/GLContext.hh"

MeshRenderer::MeshRenderer(){};

MeshRenderer::MeshRenderer(string filename){

    bool successful_load;

    std::vector<std::array<float,14>> vertex_data;
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
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 14 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // texture coord attribute
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 14 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    // normal attribute
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 14 * sizeof(float), (void*)(5 * sizeof(float)));
    glEnableVertexAttribArray(2);
    // tangent attribute
    glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, 14 * sizeof(float), (void*)(8 * sizeof(float)));
    glEnableVertexAttribArray(3);
    // bitangent attribute
    glVertexAttribPointer(4, 3, GL_FLOAT, GL_FALSE, 14 * sizeof(float), (void*)(11 * sizeof(float)));
    glEnableVertexAttribArray(4);

    number_of_vertices = index_data.size();

    vertex_data.clear();
    index_data.clear();

    this->set_render_mode(GL_FILL);
}
MeshRenderer::MeshRenderer(std::string filename, Shader shader_init) : 
        MeshRenderer::MeshRenderer(filename){
    this->shader = shader_init;
}

void MeshRenderer::render(const mat4& model_matrix){
    shader.use();
    shader.setUniformMat4("model_matrix", model_matrix);
    glBindVertexArray(VAO);
    glPolygonMode ( GL_FRONT_AND_BACK, render_mode ) ;
    glDrawElements(GL_TRIANGLES, number_of_vertices, GL_UNSIGNED_INT, 0);
}

void MeshRenderer::set_render_mode(GLenum mode){
    this->render_mode = mode;
}

void MeshRenderer::set_shader(Shader new_shader){
    shader = new_shader;
}