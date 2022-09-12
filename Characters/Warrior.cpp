//
// Created by jhpar on 12-9-2022.
//

#include "Warrior.h"
#include "TextureManager.h"
#include "Input.h"


Warrior::Warrior(Properties* props) : Character(props) {
    m_RigidBody = new RigidBody();
    m_Animation = new Animation();
    m_Animation->SetProps(m_TextureID, 1, 12, 50);
    m_Name = "Warrior";
}

void Warrior::Draw() {
    m_Animation->Draw(m_Transform->X, m_Transform->Y, m_Width, m_Height);
}

void Warrior::Clean() {
    TextureManager::GetInstance()->Clean();
}

void Warrior::Update(float dt) {

    if(Input::GetInstance()->GetKeyDown(SDL_SCANCODE_A)){
        m_Animation->SetProps("player_run", 1, 8, 50, SDL_FLIP_HORIZONTAL);
        m_RigidBody->ApplyForceX(5 * BACKWARD);
    }

    else if(Input::GetInstance()->GetKeyDown(SDL_SCANCODE_D)){
        m_Animation->SetProps("player_run", 1, 8, 50);
        m_RigidBody->ApplyForceX(5 * FORWARD);
    }

    else{
        m_RigidBody->UnSetForce();
        m_Animation->SetProps("player", 1, 12, 50);
    }

    m_RigidBody->Update(dt);

    m_Transform->TranslateX(m_RigidBody->Position().X);
    //m_Transform->TranslateY(m_RigidBody->Position().Y);

    m_Animation->Update();
}
