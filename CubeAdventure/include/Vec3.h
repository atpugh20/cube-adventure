#pragma once

class Vec3 {
private:
    float x, y, z;

public:
    Vec3(float x = 0, float y = 0, float z = 0) : x(x), y(y), z(z) {}
    
    // Standard operations
    void Add(Vec3 vec);
    void Sub(Vec3 vec);
    void Mult(float scalar);
    void Div(float scalar);
    
    // Advanced operations
    void Normalize();
    Vec3 Copy();

    // Getters
    float GetX() const;
    float GetY() const;
    float GetZ() const;
    
    float GetMagnitude() const;
    
	// Setters
	void SetX(float x);
	void SetY(float y);
	void SetZ(float z);

	void Set(float x, float y, float z);
};
