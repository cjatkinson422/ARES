#pragma once
#include <vector>
#include "GNClib/linalg.hh"
#include "GNClib/quaternion.hh"
#include "Logger.hh"

class Scene;
class SceneObject{
public:
    SceneObject();
    SceneObject(vec3 init_position, quaternion init_attitude);
    void draw(vec3 view_position, quaternion view_attitude, const double& delta_time, Scene& scene, SceneObject* drawing_object);
    virtual void tick(const double& delta_time, Scene& scene){};
    virtual void instantiate(){};
    virtual void destroy(){};

    void bind_to_parent(SceneObject* parent, bool preserve_relative_state);
    virtual void render(){Logger::println("ERROR::SCENEOBJECT::NO_RENDER_FUNCTION");};

    vec3& get_view_position();
    quaternion& get_view_attitude();
protected:

    SceneObject* parent_object = NULL;
    std::vector<SceneObject*> child_objects;
    vec3 local_position = vec3(0.0,0.0,0.0);
    vec3 view_position;
    quaternion view_attitude;
    quaternion local_attitude;
    mat4 model_matrix;

};