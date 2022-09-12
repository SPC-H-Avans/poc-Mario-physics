//
// Created by jhpar on 12-9-2022.
//

#ifndef POC_MARIO_PHYSICS_ANIMATION_H
#define POC_MARIO_PHYSICS_ANIMATION_H

#include "SDL.h"
#include <string>

class Animation {
public:
    Animation(){};
    void Update();
    void Draw(float x, float y, int spriteWidth, int spriteHeight);
    void SetProps(std::string textureID, int spriteRow, int frameCount, int animSpeed, SDL_RendererFlip flip = SDL_FLIP_NONE);
private:
    int m_SpriteRow, m_SpriteFrame;
    int m_AnimSpeed, m_FrameCount;
    std::string m_TextureID;
    SDL_RendererFlip m_Flip;

};


#endif //POC_MARIO_PHYSICS_ANIMATION_H
