//
// Created by jhpar on 12-9-2022.
//

#ifndef POC_MARIO_PHYSICS_CHARACTER_H
#define POC_MARIO_PHYSICS_CHARACTER_H

#include "GameObject.h"
#include <string>

class Character: public GameObject {
public:
    Character(Properties* props): GameObject(props){}

    virtual void Draw() = 0;
    virtual void Clean() = 0;
    virtual void Update(float dt) = 0;

protected:
    std::string m_Name;
};


#endif //POC_MARIO_PHYSICS_CHARACTER_H
