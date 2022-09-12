//
// Created by jhpar on 12-9-2022.
//

#include "Engine.h"
#include <iostream>

Engine* Engine::s_Instance = nullptr;

bool Engine::Init() {
    m_IsRunning = true;
    return true;
}

bool Engine::Clean() {
    return true;
}

void Engine::Quit() {
}

void Engine::Update() {
    std::cout << "Updating" << std::endl;
}

void Engine::Render() {

}

void Engine::Events() {

}
