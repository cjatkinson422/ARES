#pragma once
#include "GNClib/linalg.hh"
#include "GNClib/quaternion.hh"
#include "PlayerController.hh"
#include "Camera.hh"
#include "PhysicsObject.hh"
#include "HUD.hh"
#include "SceneObject.hh"
#include "Scene.hh"

class Player : public SceneObject{
public:
    Player();

    void tick(const double& delta_time, Scene& scene);
    void render();
    Camera& get_camera();
private:

    quaternion look_direction;
    
    PhysicsObject physics_object;
    PlayerController player_controller;

    HUD hud;
    Camera camera;

    double get_eva_thrust();
    double get_eva_torque();

protected:
    friend class PlayerController;
};
