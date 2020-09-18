#include "usr/Planet.hh"
#include "usr/BasicMesh.hh"
#include <glad/glad.h>


Planet::Planet(){};

Planet::Planet(double radius){

    // Basic instantiations. should go away at some point.
    shader = Shader::solid_color;
    local_position = {0.0,5.0,0.0};
    /*
     * Planets are generated using a node-based system in order to keep the ability
     * to use single precision floats on the GPU. The planetary rendering system piggybacks
     * on the rendering tree in order to provide the same level of detail and scalability.
     * However the entire planet object is stored and used together on the GPU.
     * Thus we must determine and reserve the memory for the full planetary mesh.
     * 
     * Additionally, we will utilize the node resolution as the minimum resolution of the 
     * planetary mesh. This has the effect of allowing us to calculate the initial, lowest
     * resolution, mesh using an icosphere scheme, and use the position of the triangle centers
     * as the positions of the nodes in planet-fixed coordinates. 
     */
    
    
    // Begin with a simple icosahedron
    BasicMesh::Icosphere mesh = BasicMesh::Icosphere();
    mesh.subdivide();
    mesh.subdivide();
    mesh.subdivide();

    std::vector<BasicMesh::vertex>   vertices  = mesh.vertices;
    std::vector<BasicMesh::triangle> triangles = mesh.triangles;
    
    /*
     * Based upon the radius of the planet, we want to calculate how many nodes
     * it needs to have for float32 to have millimeter precision when centered
     * on the node. 32 bit floats have approximately 7 digits of precsion. 
     * Millimeter precision would thus require distances under 10km in radius.
     * That means nodes must be no more than 20 km apar *
     * Therefore we will start a loop to compute nodes using an icosphere
     * generation formula until the edge length of the triangles are under 20 km
    */


    


    //glBindBuffer(GL_ARRAY_BUFFER, VBO);
    //glBufferData(GL_ARRAY_BUFFER, 10000, NULL, GL_DYNAMIC_DRAW);

    // now reserve the memory for the full planet object. 
    // it must be static throughout all LOD layers

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size()*sizeof(vertices[0]), vertices.data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, triangles.size()*sizeof(triangles[0]), triangles.data(), GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    number_of_vertices = triangles.size()*3;
    Logger::println("\n");
    Logger::println(number_of_vertices);

}

void Planet::render(){
    shader.use();
    shader.setUniformMat4("model_matrix", model_matrix);
    glBindVertexArray(VAO);
    glPolygonMode ( GL_FRONT_AND_BACK, GL_LINE ) ;
    glDrawElements(GL_TRIANGLES, number_of_vertices, GL_UNSIGNED_INT, 0);

}