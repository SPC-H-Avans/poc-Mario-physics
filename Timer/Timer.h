//
// Created by jhpar on 12-9-2022.
//

#ifndef POC_MARIO_PHYSICS_TIMER_H
#define POC_MARIO_PHYSICS_TIMER_H

const int TARGET_FPS = 60;
const float TARGET_DELTATIME = 1.5f;

class Timer {
public:
    void Tick();
    inline float GetDeltaTime() { return m_DeltaTime; }
    inline static Timer* GetInstance(){ return  s_Instance == nullptr ? s_Instance = new Timer() : s_Instance; }

private:
    Timer(){};
    static Timer* s_Instance;
    float m_DeltaTime;
    float m_LastTime;

};


#endif //POC_MARIO_PHYSICS_TIMER_H
