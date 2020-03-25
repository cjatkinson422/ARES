#pragma once
#include "InputHandler.hh"
#include "GNClib/linalg.hh"

class Player;
class PlayerController{
protected:
    friend class Player;
public:
    PlayerController();

private:
    Player* player;

    // EVA Thrust control callback functions
    void eva_control_thrust_forward     (double delta_time);
    void eva_control_thrust_backward    (double delta_time);
    void eva_control_thrust_left        (double delta_time);
    void eva_control_thrust_right       (double delta_time);
};
