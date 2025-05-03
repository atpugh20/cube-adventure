#pragma once

class Vec2 {
private:
    float x, y;

public:
    Vec2(float x, float y) : x(x), y(y)  {}
    
    // Standard operations
    void Add(Vec2 vec);
    void Sub(Vec2 vec);
    void Mult(float scalar);
    void Div(float scalar);
    
    // Advanced operations
    void Normalize();
    Vec2 Copy();
    
    // Getters
    float GetX() const;
    float GetY() const;
    float GetMagnitude() const;
};
