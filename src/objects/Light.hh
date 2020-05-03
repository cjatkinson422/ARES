#pragma once
#include "engine/Scene.hh"
#include "engine/SceneObject.hh"

class Light : public SceneObject{
public:
    Light();
    void tick(double delta_time, Scene& scene);
    void render(){};
private:
    double strength;
    double size;

};