#pragma once
#include "GNClib/linalg.hh"
#include "Mesh.hh"
#include "PlayerController.hh"

class Player{
public:
    Player();
private:
    vec3 position;
    vec3 velocity;
    quaternion attitude;
    quaternion look_direction;
    Mesh shader_mesh;
    Mesh collision_mesh;
    PlayerController player_controller;



    double get_mass();
    double get_eva_thrust();

protected:
    friend class PlayerController;
};
