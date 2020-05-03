#include "attributes/PhysicsObject.hh"
#include "GNClib/dynamics.hh"
#include "GNClib/quaternion.hh"

PhysicsObject::PhysicsObject(vec3& position, quaternion& attitude): position(position), inertial_to_body(attitude){

    this->velocity = {0.0,0.0,0.0};
    this->angular_velocity_body_frame = {0.0,0.0,0.0};
    this->mass = 100.0;

    this->inertial_matrix = mat3{
        {mass, 0.0, 0.0},
        {0.0, mass, 0.0},
        {0.0, 0.0, mass}
    };

    this->inertial_matrix_inverse = mat3{
        {1.0/mass, 0.0, 0.0},
        {0.0, 1.0/mass, 0.0},
        {0.0, 0.0, 1.0/mass}
    };


}


void PhysicsObject::tick(const double& delta_time){
    this->position += this->velocity * delta_time;
    this->inertial_to_body.normalize();

    quaternion ang_vel_q = 0.5 * quaternion(angular_velocity_body_frame.expand(0.0));
    quaternion inertial_to_body_dot = (ang_vel_q * inertial_to_body);

    this->inertial_to_body += inertial_to_body_dot * delta_time;
    this->inertial_to_body.normalize();
}


double PhysicsObject::get_mass(){
    return mass;
}

void PhysicsObject::add_impulse(vec3 impulse){
    this->velocity += impulse/mass;
}
void PhysicsObject::add_damping_impulse(double impulse){
    this->velocity -= velocity * impulse;
}

void PhysicsObject::add_body_frame_torque(vec3 torque_body_frame, const double& delta_time){
    vec3 angular_acceleration_body_frame = inertial_matrix_inverse * ( vec3::cross(-angular_velocity_body_frame, inertial_matrix * angular_velocity_body_frame) + torque_body_frame);
    this->angular_velocity_body_frame += angular_acceleration_body_frame * delta_time;
}

void PhysicsObject::add_body_frame_damping_torque(double torque_magnitude, const double& delta_time){
    vec3 torque = -vec3::normalize(angular_velocity_body_frame) * torque_magnitude;
    vec3 angular_acceleration_body_frame = inertial_matrix_inverse * ( vec3::cross(-angular_velocity_body_frame, inertial_matrix * angular_velocity_body_frame) + torque);
    this->angular_velocity_body_frame += angular_acceleration_body_frame * delta_time;
}