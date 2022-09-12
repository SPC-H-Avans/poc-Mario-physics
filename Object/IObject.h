//
// Created by jhpar on 12-9-2022.
//

#ifndef POC_MARIO_PHYSICS_IOBJECT_H
#define POC_MARIO_PHYSICS_IOBJECT_H


class IObject {
public:
    virtual void Draw() = 0;
    virtual void Update(float dt) = 0;
    virtual void Clean() = 0;
};


#endif //POC_MARIO_PHYSICS_IOBJECT_H
