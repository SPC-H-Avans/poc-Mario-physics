//
// Created by jhpar on 12-9-2022.
//

#ifndef POC_MARIO_PHYSICS_LAYER_H
#define POC_MARIO_PHYSICS_LAYER_H


class Layer {
public:
    virtual void Render() = 0;
    virtual void Update() = 0;
};


#endif //POC_MARIO_PHYSICS_LAYER_H
