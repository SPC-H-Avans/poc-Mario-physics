//
// Created by jhpar on 13-9-2022.
//

#ifndef POC_MARIO_PHYSICS_CAMERA_H
#define POC_MARIO_PHYSICS_CAMERA_H

#include "SDL.h"
#include "Point.h"
#include "Vector2D.h"
#include "Engine.h"

class Camera {
public:
    void Update(float dt);

    inline static Camera *GetInstance() { return s_Instance = (s_Instance != nullptr) ? s_Instance : new Camera(); }

    inline SDL_Rect GetViewBox() { return m_ViewBox; }

    inline Vector2D GetPosition() { return m_Position; }

    inline void SetTarget(Point *target) { m_Target = target; }

private:
    Camera() { m_ViewBox = {0, 0, SCREEN_WIDTH, SCREN_HEIGHT}; };

    Point *m_Target;
    Vector2D m_Position;

    SDL_Rect m_ViewBox;
    static Camera *s_Instance;
};


#endif //POC_MARIO_PHYSICS_CAMERA_H
