#pragma once
#include <GNClib/linalg.hh>
#include <GNClib/quaternion.hh>

#include "controllers/PlayerController.hh"
#include "objects/Camera.hh"

class PhysicsObject{
public:
    PhysicsObject(vec3& position, quaternion& attitude);

    void tick(const double& delta_time);
    void add_impulse(vec3 impulse);
    void add_damping_impulse(double impulse);
    void add_body_frame_torque(vec3 torque_body_frame, const double& delta_time);
    void add_body_frame_damping_torque(double torque_magnitude, const double& delta_time);
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
