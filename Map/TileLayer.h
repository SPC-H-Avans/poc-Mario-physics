//
// Created by jhpar on 12-9-2022.
//

#ifndef POC_MARIO_PHYSICS_TILELAYER_H
#define POC_MARIO_PHYSICS_TILELAYER_H

#include "Layer.h"
#include <string>
#include <vector>

struct Tileset {
    int FirstID, LastID;
    int RowCount, ColCount;
    int TileCount, TileSize;
    std::string Name, Source;
};

using TilesetList = std::vector<Tileset>;
using TileMap = std::vector<std::vector<int> >;

class TileLayer: public Layer {
public:
    TileLayer(int tileSize, int rowCount, int colCount, TileMap tileMap, TilesetList tileSets);
    virtual void Render();
    virtual void Update();
    inline TileMap GetTileMap() { return m_TileMap; }

private:
    int m_TileSize;
    int m_RowCount, m_ColCount;
    TileMap m_TileMap;
    TilesetList m_Tilesets;

};


#endif //POC_MARIO_PHYSICS_TILELAYER_H
