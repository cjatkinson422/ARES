#include "usr/LandingPad.hh"
#include "engine/TextureHandler.hh"

LandingPad::LandingPad() : SceneObject(){
    model_matrix = mat4::eye();
    shader = Shader::static_textured;
    drawing_mesh = MeshRenderer("data/models/landing_pad.obj", shader);
    texture = TextureHandler::ASPHALT_1;
}

void LandingPad::render(){
    texture.bind();
    drawing_mesh.render(model_matrix);
}

