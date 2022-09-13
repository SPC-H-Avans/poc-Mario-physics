#ifndef TILELAYER_H
#define TILELAYER_H

#include <string>
#include <vector>
#include "Layer.h"
#include "Vector2D.h"

struct Tileset{
    int FirstID, LastID;
    int RowCount, ColCount;
    int TileCount, TileSize;
    std::string Name, Source;
};

using TilesetsList = std::vector<Tileset> ;
using TileMap = std::vector<std::vector<int> >;

class TileLayer : public Layer{

    public:
        TileLayer(int tilesize, int width, int height, TileMap tilemap, TilesetsList tilesets);

        virtual void Render();
        virtual void Update();
        inline TileMap GetTileMap(){return m_Tilemap;}

    private:
        int m_TileSize;
        int m_ColCount, m_RowCount;

        TileMap m_Tilemap;
        TilesetsList m_Tilesets;
};

#endif // TILELAYER_H
