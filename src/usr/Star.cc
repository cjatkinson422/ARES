#include "usr/Star.hh"
#include "engine/Shader.hh"
#include "engine/TextureHandler.hh"

Star::Star(vec3 pos, quaternion att) : SceneObject(pos,att){
    shader = Shader::star;
    drawing_mesh = MeshRenderer("data/models/low_res_icosphere.obj", shader);
    light.bind_to_parent(this, false);
}

void Star::render(){
    drawing_mesh.render(model_matrix);
}

void Star::tick(const double& delta_time, Scene& scene){
    this->light.tick(delta_time, scene);
}