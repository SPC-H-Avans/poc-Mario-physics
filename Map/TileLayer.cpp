//
// Created by jhpar on 12-9-2022.
//

#include "TileLayer.h"

TileLayer::TileLayer(int tileSize, int rowCount, int colCount, TileMap tileMap, TilesetList tileSets): m_Tilesets(tileSize){
    m_TileSize = tileSize;
    m_RowCount = rowCount;
    m_ColCount = colCount;
    m_TileMap = tileMap;
    m_Tilesets = tileSets;
}

void TileLayer::Render() {

}

void TileLayer::Update() {

}

