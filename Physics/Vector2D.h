//
// Created by jhpar on 12-9-2022.
//

#ifndef POC_MARIO_PHYSICS_VECTOR2D_H
#define POC_MARIO_PHYSICS_VECTOR2D_H

#include <iostream>

class Vector2D {

public:
    float X, Y;
    Vector2D(float x = 0, float y = 0): X(x), Y(y){}

    inline Vector2D operator+(const Vector2D& v2) const {
        return Vector2D(X + v2.X, Y + v2.Y);
    }

    inline Vector2D operator-(const Vector2D& v2) const {
        return Vector2D(X - v2.X, Y - v2.Y);
    }

    inline Vector2D operator*(const float scalar) const {
        return Vector2D(X * scalar, Y * scalar);
    }

    void Log(std::string msg = ""){
        std::cout << msg << " X: " << X << " Y: " << Y << std::endl;
    }

private:


};


#endif //POC_MARIO_PHYSICS_VECTOR2D_H
