#pragma once
#include "engine/SceneObject.hh"
#include "attributes/MeshRenderer.hh"
#include "engine/TextureHandler.hh"
#include "engine/Texture.hh"
#include "engine/Shader.hh"

class LandingPad : public SceneObject{
public:
    LandingPad();
    void render();
private:

    MeshRenderer drawing_mesh;
    //Mesh collision_mesh;

    Texture& texture = TextureHandler::ASPHALT_1;
    Shader shader;


};