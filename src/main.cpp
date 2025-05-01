#include <iostream>

#include "../include/Vec2.hpp"

int main(void) {
    float x, y, mag;
    Vec2 position = Vec2(1, 2);
    

    x = position.GetX();
    y = position.GetY();
    mag = position.GetMagnitude();
    std::cout << "X: " << x << "\nY: " << y << "\nMag: " << mag << std::endl;

    position.Normalize();

    x = position.GetX();
    y = position.GetY();
    mag = position.GetMagnitude();
    std::cout << "X: " << x << "\nY: " << y << "\nMag: " << mag << std::endl;


    return 0;
}