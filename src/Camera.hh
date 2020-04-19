#pragma once
#include <glad/glad.h> 
#include <GLFW/glfw3.h>
#include <iostream>
#include <GNClib/linalg.hh>
#include <GNClib/quaternion.hh>
#include "SceneObject.hh"
#include "Scene.hh"

class SceneObject;
class Camera{
private:
    Camera();
    mat4 projection_matrix;

    double fovy;
    double aspect;
    double near_clip;
    double far_clip;
    GLint height;
    GLint width;

    SceneObject* parent_obj;

public:
    // Window callbacks
    void windowResizeCallback(GLint width, GLint height);
    void scrollCallback(GLdouble xoffset, GLdouble yoffset);
    void use();

    // Drawing matrices
    mat4& getProjectionMatrix();
    void updateProjectionMatrix();
    
    // state data
    quaternion local_attitude;
    vec3 local_position;

    void draw(const double& delta_time, Scene& scene);

protected:
    friend class Player;
};

