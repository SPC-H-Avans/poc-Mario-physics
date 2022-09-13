//
// Created by jhpar on 12-9-2022.
//

#include "MapParser.h"

MapParser* MapParser::s_pInstance = nullptr;

bool MapParser::Load() {
    return Parse("level1", "Assets/Maps/map.tmx");
}

void MapParser::Clean() {
    std::map<std::string, GameMap*>::iterator it;
    for(it = m_Maps.begin(); it != m_Maps.end(); ++it){
        it->second = nullptr;
    }
    m_Maps.clear();
}

bool MapParser::Parse(std::string id, std::string source) {
    TiXmlDocument xml;
    xml.LoadFile(source);

    if(xml.Error()){
        std::cerr << "Error loading map: " << source << std::endl;
        return false;
    }

    TiXmlElement* root = xml.RootElement();
    int rowCount, colCount, tileSize = 0;

    root->Attribute("width", &rowCount);
    root->Attribute("height", &colCount);
    root->Attribute("tilewidth", &tileSize);

    //Parse Tile sets
    TilesetList tilesets;
    for(TiXmlElement* e = root->FirstChildElement(); e != nullptr; e = e->NextSiblingElement()){
        if(e->Value() == std::string("tileset")){
            tilesets.push_back(ParseTileset(e));
        }
    }

    //Parse layers
    GameMap* gameMap = new GameMap();
    for(TiXmlElement* e = root->FirstChildElement(); e != nullptr; e = e->NextSiblingElement()){
        if(e->Value() == std::string("layer")){
            TileLayer* layer = ParseTileLayer(e, tilesets, tileSize, rowCount, colCount);
            gameMap->m_MapLayers.push_back(layer);
        }
    }
    m_Maps[id] = gameMap;
    return true;
}

Tileset MapParser::ParseTileset(TiXmlElement *xmlTileset) {
    Tileset tileset;
    tileset.Name = xmlTileset->Attribute("name");
    xmlTileset->Attribute("firstgid", &tileset.FirstID);
    xmlTileset->Attribute("tilecount", &tileset.TileCount);

    tileset.LastID = (tileset.FirstID + tileset.TileCount) -1;

    xmlTileset->Attribute("columns", &tileset.ColCount);
    tileset.RowCount = tileset.TileCount / tileset.ColCount;
    xmlTileset->Attribute("tilewidth", &tileset.TileSize);

    TiXmlElement* xmlImage = xmlTileset->FirstChildElement();
    std::cout << "Image source: " << xmlImage->Attribute("source") << std::endl;
    tileset.Source = xmlImage->Attribute("source");
    return tileset;
}

TileLayer *
MapParser::ParseTileLayer(TiXmlElement *xmlTileLayer, TilesetList tileset, int tileSize, int rowCount, int colCount) {
    TiXmlElement* data = nullptr;
    for(TiXmlElement* e = xmlTileLayer->FirstChildElement(); e != nullptr; e = e->NextSiblingElement()) {
        if(e->Value() == std::string("data")) {
            data = e;
            break;
        }
    }

    std::string matrix( data->GetText());
    std::istringstream inputString(matrix);
    std::string id;

    TileMap tileMap(rowCount, std::vector<int>(colCount, 0));

    for(int row = 0; row < rowCount; row++) {
        for(int col = 0; col < colCount; col++) {
            std::getline(inputString, id, ',');
            std::stringstream convertor(id);
            convertor >> tileMap[row][col];

            if(!inputString.good()) {
                break;
            }
        }
    }
    return (new TileLayer(tileSize, rowCount, colCount, tileMap, tileset));
}

