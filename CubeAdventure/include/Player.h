#pragma once

#include "Vertex.h"
#include "Vec3.h"

class Player {
private:
    Vec3 Pos;
    Vec3 Vel;
    Vec3 Acc;

public:

    float Size;

    Vertex relative_vertices[4]{
        {{-0.5f,  0.5f, 1.0f, 1.0f}, {1.0f, 1.0f, 1.0f, 1.0f}},
        {{ 0.5f,  0.5f, 1.0f, 1.0f}, {1.0f, 1.0f, 1.0f, 1.0f}},
        {{ 0.5f, -0.5f, 1.0f, 1.0f}, {1.0f, 1.0f, 1.0f, 1.0f}},
        {{-0.5f, -0.5f, 1.0f, 1.0f}, {1.0f, 1.0f, 1.0f, 1.0f}},
    };

    Vertex vertices[4]{
        {{-0.5f,  0.5f, 1.0f, 1.0f}, {1.0f, 1.0f, 1.0f, 1.0f}},
        {{ 0.5f,  0.5f, 1.0f, 1.0f}, {1.0f, 1.0f, 1.0f, 1.0f}},
        {{ 0.5f, -0.5f, 1.0f, 1.0f}, {1.0f, 1.0f, 1.0f, 1.0f}},
        {{-0.5f, -0.5f, 1.0f, 1.0f}, {1.0f, 1.0f, 1.0f, 1.0f}},
    };

    int indices[6]{
        0, 1, 2,
        2, 3, 0
    };

    Player(
        float size = 1.0f,
        float x = 0.0f, float y = 0.0f, float z = 0.0f,
        float vel_x = 0.0f, float vel_y = 0.0f, float vel_z = 0.0f,
        float acc_x = 0.0f, float acc_y = 0.0f, float acc_z = 0.0f
    );

    void UpdatePosition();

    float GetX() const;
    float GetY() const;
    float GetZ() const;

    void SetPosition(float x, float y, float z);
    void SetVelocity(float x, float y, float z);
    void SetAcceleration(float x, float y, float z);
};
