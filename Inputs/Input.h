//
// Created by jhpar on 12-9-2022.
//

#ifndef POC_MARIO_PHYSICS_INPUT_H
#define POC_MARIO_PHYSICS_INPUT_H

#include <SDL.h>

class Input {
    public:
    static Input* GetInstance() { return s_Instance = (s_Instance != nullptr) ? s_Instance : new Input(); }

    void Listen();
    bool GetKeyDown(SDL_Scancode key);

    private:
    Input();
    void KeyUp();
    void KeyDown();

    const Uint8* m_KeyStates;
    static Input* s_Instance;


};


#endif //POC_MARIO_PHYSICS_INPUT_H
