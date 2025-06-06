#include <cmath>

#include "Macros.h"
#include "Vec3.h"

// Standard operations

void Vec3::Add(Vec3 vec) {
    x += vec.x;
    y += vec.y;
    z += vec.z;
}

void Vec3::Sub(Vec3 vec) {
    x -= vec.x;
    y -= vec.y;
    z -= vec.z;
}

void Vec3::Mult(float scalar) {
    x *= scalar;
    y *= scalar;
    z *= scalar;
}

void Vec3::Div(float scalar) {
    if (scalar == 0) {
        print("Cannot divide by zero! Vector will remain the same.");
        scalar = 1;
    } 
    x /= scalar;
    y /= scalar;
    z /= scalar;
}

// Advanced operations

void Vec3::Normalize() {
    float mag = GetMagnitude();
    Div(mag);
}

Vec3 Vec3::Copy() { return Vec3(x, y, z); }

// Getters

float Vec3::GetX() const { return x; }
float Vec3::GetY() const { return y; }
float Vec3::GetZ() const { return z; }

float Vec3::GetMagnitude() const { 
    return std::sqrt(x * x + y * y + z * z); 
}

// Setters

void Vec3::SetX(float x) { this->x = x; }
void Vec3::SetY(float y) { this->y = y; }
void Vec3::SetZ(float z) { this->z = z; }

void Vec3::Set(float x, float y, float z) { 
    this->x = x; 
    this->y = y; 
    this->z = z; 
}
