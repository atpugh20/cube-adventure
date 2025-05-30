#include "Player.h"

Player::Player(
    float size, 
    float x,     float y,     float z,
    float vel_x, float vel_y, float vel_z,
    float acc_x, float acc_y, float acc_z) {
    Size = size;
    Pos = Vec3(x, y, z);
    Vel = Vec3(vel_x, vel_y, vel_z);
    Acc = Vec3(acc_x, acc_y, acc_z);
}

void Player::UpdatePosition() {
    // Update using Euler 
    Vel.Add(Acc);
    Pos.Add(Vel);

    // Set the screen vertex positions according to the position and the relative vertices
    for (int i = 0; i < 4; i++) {
        vertices[i].position[0] = 
            (relative_vertices[i].position[0] + Pos.GetX()) * Size;
        vertices[i].position[1] = 
            (relative_vertices[i].position[1] + Pos.GetY()) * Size;
        vertices[i].position[2] = 
            (relative_vertices[i].position[2] + Pos.GetZ()) * Size;
    }
}

float Player::GetX() const { return Pos.GetX(); }
float Player::GetY() const { return Pos.GetY(); }
float Player::GetZ() const { return Pos.GetZ(); }

void Player::SetPosition(float x, float y, float z) {
    Pos.Set(x, y, z);
}

void Player::SetVelocity(float x, float y, float z) {
    Vel.Set(x, y, z);
}

void Player::SetAcceleration(float x, float y, float z) {
    Acc.Set(x, y, z);
}