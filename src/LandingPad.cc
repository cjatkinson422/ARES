#include "LandingPad.hh"
#include "GLContext.hh"
#include "TextureHandler.hh"

LandingPad::LandingPad(){
    shader = GLContext::getInstance()->getShader("static_textured");
    drawing_mesh = MeshRenderer("data/models/landing_pad.obj", shader);
    texture = &TextureHandler::getInstance()->ASPHALT_1;
}

void LandingPad::draw(){
    texture->bind();
    drawing_mesh.draw();
}

