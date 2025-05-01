#include <cmath>
#include <iostream>

class Vec2 {
private:
    float x, y;

public:
    Vec2(float x, float y) : x(x), y(y) {}

    void Add(Vec2 vec) {
        x += vec.x;
        y += vec.y;
    }

    void Sub(Vec2 vec) {
        x -= vec.x;
        y -= vec.y;
    }

    void Mult(float scalar) {
        x *= scalar;
        y *= scalar;
    }

    void Div(float scalar) {
        if (scalar == 0) {
            std::cout << "Cannot divide by 0\n";
            scalar = 1; 
        }
        x /= scalar;
        y /= scalar;
    }

    void Normalize() { Div(GetMagnitude()); }
    Vec2 Copy() { return Vec2(x, y); }
    float GetMagnitude() { return std::sqrt(x * x + y * y); }
    float GetX() { return x; }
    float GetY() { return y; }
};