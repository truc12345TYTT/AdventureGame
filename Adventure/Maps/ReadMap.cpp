#include "ReadMap.h"
#include "TextureManager.h"
#include <iostream>

bool ReadMap::ReadFile(){
    std::ifstream mapFile(m_FileMap);

    if (!mapFile.is_open()) {
        std::cout << "Failed to open " << m_FileMap << " file." << std::endl;
        return false;
    }


    mapFile >> m_MapWidth >> m_MapHeight >> m_NumTiles;
    for (int y = 0; y < m_MapHeight; y++) {
        for (int x = 0; x < m_MapWidth; x++) {
            mapFile >> TileMap[y][x];
        }
    }

    mapFile.close();
    return true;
}


void ReadMap::Log(){
    for (int y = 0; y < m_MapHeight; y++) {
        for (int x = 0; x < m_MapWidth; x++) {
            std::cout << TileMap[y][x] << " ";
        }
        std::cout << std::endl;
    }
}
