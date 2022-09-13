#ifndef MAPPARSER_H
#define MAPPARSER_H

#include <map>
#include <string>
#include "GameMap.h"
#include "tinyxml.h"
#include "TileLayer.h"

class MapParser
{
   public:
        bool Load();
        void Clean();

        inline GameMap* GetMap(std::string id){return m_MapDict[id];}
        inline static MapParser* GetInstance(){ return s_Instance = (s_Instance != nullptr)? s_Instance : new MapParser();}

    private:
        MapParser(){}

        bool Parse(std::string id, std::string source);
        Tileset ParseTileset(TiXmlElement* xmlTileset);
        TileLayer* ParseTileLayer(TiXmlElement* xmlLayer, std::vector<Tileset> tilesets, int tilesize, int rowcount, int colcount);

        static MapParser* s_Instance;
        std::map<std::string, GameMap*> m_MapDict;
};

#endif // MAPPARSER_H
