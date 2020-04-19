#include "Scene.hh"
#include "Shader.hh"

void Scene::draw(const double& delta_time){
    this->render_queue.clear();
    this->light_registry.clear();

    if(bound_camera){
        bound_camera->draw(delta_time, *this);
    }

    if (light_registry.size() > 0){
        Shader::static_textured.setUniformV3("light.position", light_registry.at(0)->get_view_position());
        //light_registry.at(0)->get_view_position().println();
    }
    Shader::static_textured.setUniform1f("light.surface_intensity", 7.0e6);
    Shader::static_textured.setUniform1f("light.radius", 1.0);
    Shader::static_textured.setUniform1f("light.attenuation_coefficient", 5.0);

    for(auto const& object : render_queue){
        object->render();
    }

}
void Scene::bind_camera(Camera* camera_to_bind){
    this->bound_camera = camera_to_bind;
}

void Scene::add_to_render_queue(SceneObject* object){
    render_queue.push_back(object);
}

void Scene::register_light(Light* light){
    light_registry.push_back(light);
}