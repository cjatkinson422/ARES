#pragma once
#include <vector>
#include "SceneObject.hh"

class Scene{
public:
    Scene(){};
    void render();

    // TODO implement remove
    void add_scene_object(SceneObject* object);
private:

    std::vector<SceneObject*> objects_in_scene;
};