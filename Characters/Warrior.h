//
// Created by jhpar on 12-9-2022.
//

#ifndef POC_MARIO_PHYSICS_WARRIOR_H
#define POC_MARIO_PHYSICS_WARRIOR_H

#include "Character.h"
#include "Animation.h"
#include "RigidBody.h"

class Warrior: public Character {
public:
    Warrior(Properties* props);

    virtual void Draw();
    virtual void Clean();
    virtual void Update(float dt);

private:
    Animation* m_Animation;
    RigidBody* m_RigidBody;


};


#endif //POC_MARIO_PHYSICS_WARRIOR_H
