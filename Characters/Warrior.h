//
// Created by jhpar on 12-9-2022.
//

#ifndef POC_MARIO_PHYSICS_WARRIOR_H
#define POC_MARIO_PHYSICS_WARRIOR_H

#include "Character.h"

class Warrior: public Character {
public:
    Warrior(Properties* props);

    virtual void Draw();
    virtual void Clean();
    virtual void Update(float dt);

private:
    int m_Row, m_Frame, m_FrameCount;
    int m_AnimSpeed;

};


#endif //POC_MARIO_PHYSICS_WARRIOR_H
