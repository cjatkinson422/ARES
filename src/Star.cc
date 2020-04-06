#include "Star.hh"
#include "GLContext.hh"
#include "TextureHandler.hh"

Star::Star(){
    shader = GLContext::getInstance()->getShader("star");
    drawing_mesh = MeshRenderer("data/models/low_res_icosphere.obj", shader);
    texture = &TextureHandler::getInstance()->ASPHALT_1;
}

void Star::draw(){
    texture->bind();
    drawing_mesh.draw();
}

