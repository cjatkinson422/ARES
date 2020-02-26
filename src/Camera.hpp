#pragma once
#include <glad/glad.h> 
#include <GLFW/glfw3.h>
#include <iostream>
#include <GNClib/linalg.hpp>

class Camera{
private:
    Camera();
    static Camera* instance;

    quaternion rotation;
    vec3 position;

    static mat4 ProjectionMat(double fovy, double aspect, double nearClip, double farClip);


public:
    static Camera* getInstance();
    void windowResizeCallback(GLint width, GLint height);
    void scrollCallback(GLdouble xoffset, GLdouble yoffset);
};

