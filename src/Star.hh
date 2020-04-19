#pragma once
#include "SceneObject.hh"
#include "MeshRenderer.hh"
#include "Texture.hh"
#include "Shader.hh"
#include "Light.hh"

class Star : public SceneObject{
public:
    Star(vec3 pos, quaternion att);
    void render();
    void tick(const double& delta_time, Scene& scene);
private:

    MeshRenderer drawing_mesh;
    //Mesh collision_mesh;

    Texture* texture = NULL;
    Shader shader = Shader::star;
    Light light;


};