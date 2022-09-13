//
// Created by jhpar on 12-9-2022.
//

#include "Engine.h"
#include <iostream>
#include "TextureManager.h"
#include "Input.h"
#include "Timer.h"
#include "MapParser.h"
#include "Warrior.h"
#include <iostream>

Engine* Engine::s_Instance = nullptr;
Warrior* player = nullptr;

bool Engine::Init() {
    if(SDL_Init(SDL_INIT_VIDEO) != 0 && IMG_Init(IMG_INIT_PNG | IMG_INIT_PNG) != 0){
        SDL_Log("Failed to initialize SDL: %s", SDL_GetError());
        return false;
    }

    SDL_WindowFlags  windowFlags = (SDL_WindowFlags)(SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);

    m_Window = SDL_CreateWindow("Mario Physics", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, windowFlags);
    if(!m_Window){
        SDL_Log("Failed to create window: %s", SDL_GetError());
        return false;
    }

    m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(!m_Renderer){
        SDL_Log("Failed to create renderer: %s", SDL_GetError());
        return false;
    }

    if(!MapParser::GetInstance()->Load()){
        std::cout << "Failed to load map" << std::endl;
    }

    m_LevelMap = MapParser::GetInstance()->GetMap("level1");

    TextureManager::GetInstance()->Load("player", "Assets/character/anim/idle/spritesheet.png");
    TextureManager::GetInstance()->Load("player_run", "Assets/character/anim/run/spritesheet.png");
    player = new Warrior(new Properties("player", 100, 200, 131, 142));
    return m_IsRunning = true;
}

bool Engine::Clean() {
    TextureManager::GetInstance()->Clean();
    SDL_DestroyRenderer(m_Renderer);
    SDL_DestroyWindow(m_Window);
    IMG_Quit();
    SDL_Quit();
    return true;
}

void Engine::Quit() {
    m_IsRunning = false;
}

void Engine::Update() {
    float deltaTime = Timer::GetInstance()->GetDeltaTime();
    m_LevelMap->Update();
    player->Update(deltaTime);
}

void Engine::Render() {
    SDL_SetRenderDrawColor(m_Renderer, 124, 210, 254, 255);
    SDL_RenderClear(m_Renderer);

    m_LevelMap->Render();
    player->Draw();

    SDL_RenderPresent(m_Renderer);
}

void Engine::Events() {
    Input::GetInstance()->Listen();
}
