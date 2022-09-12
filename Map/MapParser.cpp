//
// Created by jhpar on 12-9-2022.
//

#include "MapParser.h"

bool MapParser::Load() {
    return Parse("level1", "Assets/Maps/map.tmx")
}

void MapParser::Clean() {

}

GameMap *MapParser::GetMaps() {

}

bool MapParser::Parse(std::string id, std::string source) {

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
    tileset.Source = xmlImage->Attribute("source");
    return tileset
}

TileLayer *
MapParser::ParseTileLayer(TiXmlElement *xmlTileLayer, Tileset tileset, int tileSize, int rowCount, int colCount) {

}

MapParser::MapParser() {

}
