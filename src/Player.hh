#pragma once
#include "GNClib/linalg.hh"
#include "GNClib/quaternion.hh"
#include "Mesh.hh"
#include "PlayerController.hh"
#include "Camera.hh"
#include "PhysicsObject.hh"
#include "HUD.hh"

class Player{
public:
    Player();

    void tick(double delta_time);
    void draw();
private:
    vec3 position;
    quaternion rotation;

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
