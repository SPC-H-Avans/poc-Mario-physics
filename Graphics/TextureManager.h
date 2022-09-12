//
// Created by jhpar on 12-9-2022.
//

#ifndef POC_MARIO_PHYSICS_TEXTUREMANAGER_H
#define POC_MARIO_PHYSICS_TEXTUREMANAGER_H

#include <string>
#include <map>
#include "SDL.h"
#include "SDL_image.h"


class TextureManager {

public:
    static TextureManager* GetInstance() { return s_Instance = (s_Instance != nullptr) ? s_Instance : new TextureManager(); }

    bool Load(std::string id, std::string fileName);
    void Drop(std::string id);
    void Clean();

    void Draw(std::string id, int x, int y, int width, int height, SDL_RendererFlip flip = SDL_FLIP_NONE);

private:
    TextureManager(){};
    std::map<std::string, SDL_Texture*> m_TextureMap;
    static TextureManager* s_Instance;
};



#endif //POC_MARIO_PHYSICS_TEXTUREMANAGER_H
