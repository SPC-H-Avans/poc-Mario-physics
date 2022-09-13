//
// Created by jhpar on 13-9-2022.
//

#ifndef POC_MARIO_PHYSICS_POINT_H
#define POC_MARIO_PHYSICS_POINT_H

#include <iostream>

class Point {
public:
    float X, Y;

    Point(float X = 0, float Y = 0) : X(X), Y(Y) {}

    inline Point operator+(const Point &other) const {
        return Point(X + other.X, Y + other.Y);
    }

    inline friend Point operator+=(Point &p1, const Point &p2) {
        p1.X += p2.X;
        p1.Y += p2.Y;
        return p1;
    }

    inline Point operator-(const Point &other) const {
        return Point(X - other.X, Y - other.Y);
    }

    inline friend Point operator-=(Point &p1, const Point &p2) {
        p1.X -= p2.X;
        p1.Y -= p2.Y;
        return p1;
    }

    inline Point operator*(const float scalar) const {
        return Point(X * scalar, Y * scalar);
    }

    void Log(std::string msg = "") {
        std::cout << msg << " X: " << X << " Y: " << Y << std::endl;
    }
};


#endif //POC_MARIO_PHYSICS_POINT_H
