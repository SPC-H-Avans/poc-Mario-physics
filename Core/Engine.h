//
// Created by jhpar on 12-9-2022.
//

#ifndef POC_MARIO_PHYSICS_ENGINE_H
#define POC_MARIO_PHYSICS_ENGINE_H

#include "SDL.h"
#include "GameMap.h"
#include <SDL_image.h>

#define SCREEN_WIDTH 960
#define SCREEN_HEIGHT 640


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
    inline SDL_Renderer* GetRenderer() { return m_Renderer; }

private:
    Engine(){}
    bool m_IsRunning;

    GameMap* m_LevelMap;
    SDL_Window* m_Window;
    SDL_Renderer* m_Renderer;

    static Engine* s_Instance;


};


#endif //POC_MARIO_PHYSICS_ENGINE_H
