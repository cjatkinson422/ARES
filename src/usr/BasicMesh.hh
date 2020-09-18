#pragma once
#include "GNClib/vec3f.hh"
#include <vector>
#include <array>
#include <glad/glad.h>

namespace BasicMesh{


using vertex = vec3f;
using triangle = std::array<GLuint, 3>;
using edge = std::array<GLuint,2>;


class Icosphere {
public:
    Icosphere();
    void subdivide();


    std::vector<vertex> vertices = icosahedron_vertices;
    std::vector<triangle> triangles = icosahedron_triangles;
    //static void generate_mesh(std::vector<vertex>& vertices, 
    //                          std::vector<triangle>& triangles,
    //                          unsigned int subdivision_level);

    static constexpr double A = 0.525731112119133606;
    static constexpr double B = 0.850650808352039932;
    static constexpr double C = 0.000000000000000000;
    static const std::vector<vertex> icosahedron_vertices;
    static const std::vector<triangle> icosahedron_triangles;
private:


// Icosahedron constants


}; // End class Icosphere

}; // End namespace BasicMesh
