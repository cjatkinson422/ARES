#include "Light.hh"

Light::Light():SceneObject(){

};

void Light::tick(double delta_time, Scene& scene){
    scene.register_light(this);
}