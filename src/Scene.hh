#pragma once
#include <vector>
#include "SceneObject.hh"
#include "Camera.hh"

class Scene{
public:
    Scene(){};
    void render(Camera* camera);

    // TODO implement remove
    void add_scene_object(SceneObject* object);
    void remove_scene_object(SceneObject* object);
private:

    std::vector<SceneObject*> objects_in_scene;
};