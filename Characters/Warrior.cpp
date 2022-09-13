#include "Warrior.h"
#include "TextureManager.h"
#include "SDL.h"
#include "Input.h"


Warrior::Warrior(Properties *props) : Character(props) {
    m_RigidBody = new RigidBody();
    m_Animation = new Animation();
    m_Animation->SetProps(m_TextureID, 1, 12, 100);
}

void Warrior::Draw() {
    m_Animation->Draw(m_Transform->X, m_Transform->Y, m_Width, m_Height);
}

void Warrior::Update(float dt) {

    m_Animation->SetProps("player", 1, 12, 100);
    m_RigidBody->UnSetForce();

    if (Input::GetInstance()->GetKeyDown(SDL_SCANCODE_A)) {
        m_RigidBody->ApplyForceX(5 * BACKWARD);
        m_Animation->SetProps("player_run", 1, 8, 100, SDL_FLIP_HORIZONTAL);
    }

    if (Input::GetInstance()->GetKeyDown(SDL_SCANCODE_D)) {
        m_RigidBody->ApplyForceX(5 * FORWARD);
        m_Animation->SetProps("player_run", 1, 8, 100);
    }

    m_RigidBody->Update(dt);

    m_Transform->TranslateX(m_RigidBody->Position().X);
    //m_Transform->TranslateY(m_RigidBody->Position().Y);

    m_Origin->X = m_Transform->X + (m_Width / 2);
    m_Origin->Y = m_Transform->Y + (m_Height / 2);

    m_Animation->Update();
}

void Warrior::Clean() {
    TextureManager::GetInstance()->Clean();
}

