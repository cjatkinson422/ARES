#pragma once
#include "SceneObject.hh"
#include "MeshRenderer.hh"
#include "Texture.hh"
#include "Shader.hh"

class Star : public SceneObject{
public:
    Star();
    void draw();
private:

    MeshRenderer drawing_mesh;
    //Mesh collision_mesh;

    Texture* texture = NULL;
    Shader* shader = NULL;


};