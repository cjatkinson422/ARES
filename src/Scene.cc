#include "Scene.hh"


void Scene::render(){
    for(auto const& object : objects_in_scene){
        object->draw();
    }
}


void Scene::add_scene_object(SceneObject* object){
    objects_in_scene.push_back(object);
}