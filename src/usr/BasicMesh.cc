#include <usr/BasicMesh.hh>
#include <glad/glad.h>
#include <algorithm>
#include <iostream>
using namespace BasicMesh;


Icosphere::Icosphere(){

    // Set distance to infinity to begin with.
    double node_distance = std::numeric_limits<double>::max();
    // Continue subdividing until vertices (and thus the nodes) are less than 20 km apart
    while (node_distance > 20000.0){
        

        break;
    }
}

void Icosphere::subdivide(){
    size_t num_triangles = triangles.size();
    triangles.reserve(num_triangles*3);
    vertices.reserve(vertices.size()*4);

    for(size_t i = 0; i < num_triangles; ++i){
        // Reference to this triangle object
        triangle& tri = triangles.at(i);
        // References to the three vertices that make up this triangle
        vertex& v0 = vertices.at(tri.at(0));
        vertex& v1 = vertices.at(tri.at(1));
        vertex& v2 = vertices.at(tri.at(2));
        // Index of the starting location of the 3 newly added vertices
        GLuint v3 = vertices.size();
        // Add the three new vertices that are the center of each edge of the main tri
        vertices.push_back(vertex::normalize( (v0+v1)/2.0f ));
        vertices.push_back(vertex::normalize( (v1+v2)/2.0f ));
        vertices.push_back(vertex::normalize( (v2+v0)/2.0f ));
        // Add the three new triangles to the element buffer
        triangles.push_back({tri.at(0), v3  , v3+2});
        triangles.push_back({tri.at(1), v3+1, v3  });
        triangles.push_back({tri.at(2), v3+2, v3+1});
        // then overwrite the original triangle with the one at the center of the newly subdivided face
        triangles.at(i) = {v3, v3+1, v3+2};
    }
    
}

const std::vector<vertex> Icosphere::icosahedron_vertices = {
    vertex(-A, C, B), vertex(A, C, B), vertex(-A, C,-B),
    vertex( A, C,-B), vertex(C, B, A), vertex( C, B,-A),
    vertex( C,-B, A), vertex(C,-B,-A), vertex( B, A, C),
    vertex(-B, A, C), vertex(B,-A, C), vertex(-B,-A, C)
};

const std::vector<triangle> Icosphere::icosahedron_triangles = {
    {0,4,1},    {0,4,9},    {9,5,4},
    {4,5,8},    {4,8,1},    {8,1,10},
    {8,3,10},   {5,3,8},    {5,2,3},
    {2,7,3},    {7,10,3},   {7,6,10},
    {7,11,6},   {11,0,6},   {0,1,6},
    {6,1,10},   {9,0,11},   {9,11,2},
    {9,2,5},    {7,2,11}
};

//static void Icosphere::generate_mesh(std::vector<vertex>& vertices, 
//                              std::vector<triangle>& triangles,
//                              unsigned int subdivision_level){
//
//}