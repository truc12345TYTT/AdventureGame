#include "GameMap.h"
#include "TextureManager.h"
#include <iostream>

void GameMap::Draw(std::string _MapID){
    for (int i = 0; i < m_MapHeight; i ++){
        for (int j = 0; j < m_MapWidth; j ++){
            int index = TileMap[i][j];
            if (index == 0) continue;
            else{
                TextureManager::GetInstance()->DrawTileMap(_MapID, index - 1, j*TILE_SIZE, i*TILE_SIZE, TILE_SIZE);
            }
        }
    }
}


void GameMap::SetRectTileMap(){
    for (int i = 0; i < m_MapHeight; i ++){
        for (int j = 0; j < m_MapWidth; j ++){
            SetRectTile(i, j, TILE_SIZE);
            //std::cout << cam.X << ' ' << cam.Y << std::endl;
        }
    }
}

void GameMap::Clean(){
    TextureManager::GetInstance()->Clean();
}

