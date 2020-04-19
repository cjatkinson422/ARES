#pragma once
#include <vector>
#include "SceneObject.hh"
#include "Camera.hh"
#include "Light.hh"

class SceneObject;
class Camera;
class Light;
class Scene{
public:
    Scene(){};

    void add_to_render_queue(SceneObject* object);
    void register_light(Light* light);
    void draw(const double& delta_time);
    void bind_camera(Camera* camera_to_bind);
private:
    Camera* bound_camera = NULL;
    std::vector<SceneObject*> render_queue;
    std::vector<Light*> light_registry;
};