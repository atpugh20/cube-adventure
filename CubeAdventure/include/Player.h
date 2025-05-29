#pragma once

#include "Vertex.h"
#include "Vec3.h"

class Player {
public:
    Vec3 Pos;
    Vec3 Vel;
    Vec3 Acc;

    float Size;

    Vertex relative_vertices[4] {
        {{-0.5f,  0.5f, 1.0f, 1.0f}, {1.0f, 1.0f, 1.0f, 1.0f}},
        {{ 0.5f,  0.5f, 1.0f, 1.0f}, {1.0f, 1.0f, 1.0f, 1.0f}},
        {{ 0.5f, -0.5f, 1.0f, 1.0f}, {1.0f, 1.0f, 1.0f, 1.0f}},
        {{-0.5f, -0.5f, 1.0f, 1.0f}, {1.0f, 1.0f, 1.0f, 1.0f}},
    };

    Vertex vertices[4] {
        {{-0.5f,  0.5f, 1.0f, 1.0f}, {1.0f, 1.0f, 1.0f, 1.0f}},
        {{ 0.5f,  0.5f, 1.0f, 1.0f}, {1.0f, 1.0f, 1.0f, 1.0f}},
        {{ 0.5f, -0.5f, 1.0f, 1.0f}, {1.0f, 1.0f, 1.0f, 1.0f}},
        {{-0.5f, -0.5f, 1.0f, 1.0f}, {1.0f, 1.0f, 1.0f, 1.0f}},
    };

    int indices[6] {
        0, 1, 2,
        2, 3, 0
    };

    Player(
        float size = 1.0f,
		float x = 0, float vel_x = 0, float acc_x = 0,
		float y = 0, float vel_y = 0, float acc_y = 0,
		float z = 0, float vel_z = 0, float acc_z = 0
    );

    void Update();
};
