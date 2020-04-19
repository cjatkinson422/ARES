#pragma once
#include "InputHandler.hh"
#include "GNClib/linalg.hh"

class Player;
class PlayerController{
protected:
    friend class Player;
public:
    PlayerController(Player* player);

    void use();

    void eva_rotational_damp(const double& delta_time);
    void eva_translational_damp(const double& delta_time);
private:
    Player* player;

    // EVA Thrust control callback functions
    void eva_control_thrust_forward     (const double& delta_time);
    void eva_control_thrust_backward    (const double& delta_time);
    void eva_control_thrust_left        (const double& delta_time);
    void eva_control_thrust_right       (const double& delta_time);
    void eva_control_thrust_up          (const double& delta_time);
    void eva_control_thrust_down        (const double& delta_time);

    void eva_slew(const double& delta_time, double x_strength, double y_strength);

};
