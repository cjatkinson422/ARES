#pragma once
#include <GNClib/linalg.hh>
#include <GNClib/quaternion.hh>

#include "Mesh.hh"
#include "PlayerController.hh"
#include "Camera.hh"

class PhysicsObject{
public:
    PhysicsObject(vec3& position, quaternion& attitude);

    void tick(double delta_time);
    void add_impulse(vec3 impulse);
    void add_angular_impulse(vec3 torque_body_frame, double delta_time);
    double get_mass();
private:
    vec3& position;
    vec3 velocity;
    quaternion& inertial_to_body;
    vec3 angular_velocity_body_frame;

    double mass;
    mat3 inertial_matrix;
    mat3 inertial_matrix_inverse;


protected:
};
