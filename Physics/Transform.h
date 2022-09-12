//
// Created by jhpar on 12-9-2022.
//

#ifndef POC_MARIO_PHYSICS_TRANSFORM_H
#define POC_MARIO_PHYSICS_TRANSFORM_H

#include "Vector2D.h"

class Transform {

public:
    float X, Y;

    Transform(float x = 0, float y = 0): X(x), Y(y) {};
    void Log(std::string msg = ""){
        std::cout << msg << " X: " << X << " Y: " << Y << std::endl;
    }

private:
    inline void TranslateX(float x) { X += x; }
    inline void TranslateY(float y) { Y += y; }
    inline void Translate(Vector2D v) { X += v.X; Y += v.Y; }


};


#endif //POC_MARIO_PHYSICS_TRANSFORM_H
