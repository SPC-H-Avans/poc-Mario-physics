//
// Created by jhpar on 12-9-2022.
//

#include "Warrior.h"
#include "TextureManager.h"


Warrior::Warrior(Properties* props) : Character(props) {
    m_RigidBody = new RigidBody();
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
    m_RigidBody->Update(0.4);
    m_RigidBody->ApplyForceX(2);

    m_Transform->TranslateX(m_RigidBody->Position().X);
    m_Transform->TranslateY(m_RigidBody->Position().Y);

    m_Animation->Update();
}
