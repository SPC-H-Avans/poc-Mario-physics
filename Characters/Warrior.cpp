//
// Created by jhpar on 12-9-2022.
//

#include "Warrior.h"
#include "TextureManager.h"
#include "SDL.h"


Warrior::Warrior(Properties* props) : Character(props) {
    m_Name = "Warrior";
    m_Row = 1;
    m_Frame = 0;
    m_FrameCount = 12;
    m_AnimSpeed = 40;
}

void Warrior::Draw() {
    TextureManager::GetInstance()->DrawFrame(m_TextureID, m_Transform->X, m_Transform->Y, m_Width, m_Height, m_Row, m_Frame);
}

void Warrior::Clean() {
    TextureManager::GetInstance()->Clean();
}

void Warrior::Update(float dt) {
    m_Frame = (SDL_GetTicks()/m_AnimSpeed) % m_FrameCount;
}
