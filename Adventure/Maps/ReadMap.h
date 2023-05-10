#ifndef READMAP_H
#define READMAP_H

#include <string>
#include <fstream>
#include <vector>

#define MAX_SIZE_MAP 200

using tileMap = int[MAX_SIZE_MAP][MAX_SIZE_MAP];
//using tileMap = std::vector<std::vector<int>>;

class ReadMap
{
    public:
        ReadMap(std::string _filemap) {m_FileMap = _filemap;}

        bool ReadFile();

        void Log();

        inline int GetValue(int row, int col){return TileMap[row][col];}
        inline int GetNumCol() {return m_MapWidth;}
        inline int GetNumRow() {return m_MapHeight;}

    protected:
        std::string m_FileMap;
        int m_MapWidth, m_MapHeight, m_NumTiles;
        tileMap TileMap;
};

#endif // READMAP_H
