#include "../include/Vec2.hpp"

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
        std::cout << "Cannot divide by 0\n";
        scalar = 1; 
    }
    x /= scalar;
    y /= scalar;
}

void  Vec2::Normalize() { Div(GetMagnitude()); }
Vec2  Vec2::Copy() { return Vec2(x, y); }
float Vec2::GetMagnitude() { return std::sqrt(x * x + y * y); }
float Vec2::GetX() { return x; }
float Vec2::GetY() { return y; }
