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

    void eva_rotational_damp(double delta_time);
    void eva_translational_damp(double delta_time);
private:
    Player* player;

    // EVA Thrust control callback functions
    void eva_control_thrust_forward     (double delta_time);
    void eva_control_thrust_backward    (double delta_time);
    void eva_control_thrust_left        (double delta_time);
    void eva_control_thrust_right       (double delta_time);
    void eva_control_thrust_up          (double delta_time);
    void eva_control_thrust_down        (double delta_time);

    void eva_slew(double delta_time, double x_strength, double y_strength);

};
