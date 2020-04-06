#pragma once
#include "SceneObject.hh"
#include "MeshRenderer.hh"
#include "Texture.hh"
#include "Shader.hh"

class LandingPad : public SceneObject{
public:
    LandingPad();
    void draw();
private:

    MeshRenderer drawing_mesh;
    //Mesh collision_mesh;

    Texture* texture = NULL;
    Shader* shader = NULL;


};