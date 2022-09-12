//
// Created by jhpar on 12-9-2022.
//

#include "Engine.h"
#include <iostream>
#include "TextureManager.h"

Engine* Engine::s_Instance = nullptr;

bool Engine::Init() {
    if(SDL_Init(SDL_INIT_VIDEO) != 0 && IMG_Init(IMG_INIT_PNG | IMG_INIT_PNG) != 0){
        SDL_Log("Failed to initialize SDL: %s", SDL_GetError());
        return false;
    }

    m_Window = SDL_CreateWindow("Mario Physics", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    if(!m_Window){
        SDL_Log("Failed to create window: %s", SDL_GetError());
        return false;
    }

    m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(!m_Renderer){
        SDL_Log("Failed to create renderer: %s", SDL_GetError());
        return false;
    }

    TextureManager::GetInstance()->Load("tree", "Assets/tree.png");
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
}

void Engine::Render() {
    SDL_SetRenderDrawColor(m_Renderer, 124, 210, 254, 255);
    SDL_RenderClear(m_Renderer);
    TextureManager::GetInstance()->Draw("tree", 100, 100, 800, 684);
    SDL_RenderPresent(m_Renderer);
}

void Engine::Events() {
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type) {
        case SDL_QUIT:
            Quit();
            break;
        default:
            break;
    }
}
