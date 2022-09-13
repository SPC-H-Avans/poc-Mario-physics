//
// Created by jhpar on 12-9-2022.
//

#ifndef POC_MARIO_PHYSICS_MAPPARSER_H
#define POC_MARIO_PHYSICS_MAPPARSER_H

#include "tinyxml.h"
#include <map>
#include <string>
#include "GameMap.h"
#include "TileLayer.h"


class MapParser {
public:
    bool Load();
    void Clean();

    inline GameMap* GetMap(std::string id) { return m_Maps[id]; }

    inline static MapParser* GetInstance() {
        if(s_pInstance == 0) {
            s_pInstance = new MapParser();
        }
        return s_pInstance;
    }

private:
    MapParser(){}
    static MapParser *s_pInstance;
    std::map<std::string, GameMap*> m_Maps;

    bool Parse(std::string id, std::string source);
    Tileset ParseTileset(TiXmlElement* xmlTileset);
    TileLayer* ParseTileLayer(TiXmlElement* xmlTileLayer, TilesetList tileset, int tileSize, int rowCount, int colCount);
};


#endif //POC_MARIO_PHYSICS_MAPPARSER_H
