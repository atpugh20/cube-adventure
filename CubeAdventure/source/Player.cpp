#include "Player.h"

Player::Player(float size, float x, float y, float vel_x, float vel_y, float acc_x, float acc_y) {
    Size = size;
    Pos = Vec2(x, y);
    Vel = Vec2(vel_x, vel_y);
    Acc = Vec2(acc_x, acc_y);
}

void Player::Update() {
    Vel.Add(Acc);
    Pos.Add(Vel);

    // Set the screen vertex positions according to the position and the relative vertices
    for (int i = 0; i < 4; i++) {
        vertices[i].position[0] = (relative_vertices[i].position[0] + Pos.GetX()) * Size;
        vertices[i].position[1] = (relative_vertices[i].position[1] + Pos.GetY()) * Size;
    }
}