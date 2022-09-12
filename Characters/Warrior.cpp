//
// Created by jhpar on 12-9-2022.
//

#include "Warrior.h"
#include "TextureManager.h"
#include "SDL.h"


Warrior::Warrior(Properties* props) : Character(props) {
    m_Animation = new Animation();
    m_Animation->SetProps(m_TextureID, 1, 12, 50, SDL_FLIP_HORIZONTAL);
    m_Name = "Warrior";
}

void Warrior::Draw() {
    m_Animation->Draw(m_Transform->X, m_Transform->Y, m_Width, m_Height);
}

void Warrior::Clean() {
    TextureManager::GetInstance()->Clean();
}

void Warrior::Update(float dt) {
    m_Animation->Update();
}
