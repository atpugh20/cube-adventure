#pragma once

#include "Vec2.h"

class Player {
private:
    Vec2 pos;
    Vec2 vel;
    Vec2 acc;

    float size;

public:
    Player(float size = 0, float x = 0, float y = 0, 
        float vel_x = 0, float vel_y = 0, float acc_x = 0, float acc_y = 0) 
        : size(size), 
          pos (Vec2(x, y)), 
          vel (Vec2(vel_x, vel_y)), 
          acc (Vec2(acc_x, acc_y)) 
    {}
    
    void Update();
    void Draw();
};
