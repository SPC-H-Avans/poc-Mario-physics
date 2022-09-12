//
// Created by jhpar on 12-9-2022.
//

#ifndef POC_MARIO_PHYSICS_ENGINE_H
#define POC_MARIO_PHYSICS_ENGINE_H


class Engine {

public:
    static Engine* GetInstance(){
        return s_Instance = (s_Instance != nullptr) ? s_Instance : new Engine();
    }
    bool Init();
    bool Clean();
    void Quit();

    void Update();
    void Render();
    void Events();

    inline bool IsRunning() { return m_IsRunning; }

private:
    Engine(){}
    static Engine* s_Instance;
    bool m_IsRunning;


};


#endif //POC_MARIO_PHYSICS_ENGINE_H
