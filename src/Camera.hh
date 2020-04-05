#pragma once
#include <glad/glad.h> 
#include <GLFW/glfw3.h>
#include <iostream>
#include <GNClib/linalg.hh>
#include <GNClib/quaternion.hh>

class Camera{
private:
    Camera();

    quaternion rotation;
    vec3 position;
    mat4 view_projection_matrix;
    mat4 view_matrix;
    mat4 projection_matrix;

    double fovy;
    double aspect;
    double near_clip;
    double far_clip;
    GLint height;
    GLint width;




public:
    void windowResizeCallback(GLint width, GLint height);
    void scrollCallback(GLdouble xoffset, GLdouble yoffset);
    mat4& getViewProjectionMatrix();
    void updateProjectionMatrix();
    void updateViewMatrix();
    void use();

protected:
    friend class Player;
};

