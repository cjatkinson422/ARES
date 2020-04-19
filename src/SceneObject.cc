#include "SceneObject.hh"
#include "Scene.hh"

SceneObject::SceneObject() : 
        local_position(vec3(0.0,0.0,0.0)), local_attitude(quaternion())
    {
}

SceneObject::SceneObject(vec3 init_position, quaternion init_attitude) : 
        local_position(init_position), local_attitude(init_attitude){

}


void SceneObject::bind_to_parent(SceneObject* parent, bool preserve_relative_state){
    // TODO: add protection against binding the same object to multiple parents.
    parent_object = parent;

    if(preserve_relative_state){
        local_position -= parent_object->local_position;
        local_attitude = local_attitude * parent_object->local_attitude.conj();
    }

    parent_object->child_objects.push_back(this);
}

void SceneObject::draw(vec3 view_position, quaternion view_attitude, const double& delta_time, Scene& scene, SceneObject* drawing_object){
    // TODO get rid of variable shadowing of view_position and view_attitude

    if(parent_object == drawing_object){
        view_attitude = view_attitude * local_attitude.conj();
        view_position = view_position + view_attitude.rotate(local_position);
    }

    model_matrix = mat4::eye();
    model_matrix[0][3] = view_position[0];
    model_matrix[1][3] = view_position[1];
    model_matrix[2][3] = view_position[2];
    model_matrix = model_matrix * view_attitude.toMat3().expand();
    this->view_position = view_position;
    this->view_attitude = view_attitude;
    this->tick(delta_time, scene);

    if(parent_object != drawing_object){
        view_attitude = view_attitude * local_attitude.conj();
        view_position = view_position - view_attitude.rotate(local_position);
        if(parent_object)
            parent_object->draw(view_position, view_attitude, delta_time, scene, this);
    }

    for(SceneObject* child : child_objects){
        if(child != drawing_object){
            child->draw(view_position, view_attitude, delta_time, scene, this);
        }
    }
    scene.add_to_render_queue(this);

}


vec3& SceneObject::get_view_position(){
    return view_position;
}