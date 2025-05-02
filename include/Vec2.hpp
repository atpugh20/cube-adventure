#include <cmath>
#include <iostream>

class Vec2 {
private:
    float x, y;

public:
    Vec2(float x, float y) : x(x), y(y) {}

    // Standard Operations
    void Add(Vec2 vec);
    void Sub(Vec2 vec);
    void Mult(float scalar);
    void Div(float scalar);

    // Advanced Operations
    Vec2 Copy();
    void Normalize();

    // Getters
    float GetMagnitude();
    float GetX();
    float GetY();
};