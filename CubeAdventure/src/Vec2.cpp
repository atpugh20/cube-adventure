#include <cmath>

#include "Macros.h"
#include "Vec2.h"

// Standard operations

void Vec2::Add(Vec2 vec) {
    x += vec.x;
    y += vec.y;
}

void Vec2::Sub(Vec2 vec) {
    x -= vec.x;
    y -= vec.y;
}

void Vec2::Mult(float scalar) {
    x *= scalar;
    y *= scalar;
}

void Vec2::Div(float scalar) {
    if (scalar == 0) {
        print("Cannot divide by zero!");
        scalar = 1;
    } 
    x /= scalar;
    y /= scalar;
}

// Advanced operations

void Vec2::Normalize() {
    float mag = GetMagnitude();
    Div(mag);
}

Vec2 Vec2::Copy() { return Vec2(x, y); }

// Getters

float Vec2::GetX() const { return x; }

float Vec2::GetY() const { return y; }

float Vec2::GetMagnitude() const { return std::sqrt(x * x + y * y); }
