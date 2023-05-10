#ifndef GAMEMAP_H
#define GAMEMAP_H

#include "ReadMap.h"
#include "SDL.h"
#include "Camera.h"
#include "Vector2D.h"

#define TILE_SIZE 16

class GameMap : public ReadMap
{
    public:
        GameMap(std::string _FileMap) : ReadMap(_FileMap) {};
        void Draw(std::string _MapID);
        void Clean();

        inline SDL_Rect GetRectTileMap(int row, int col) {return m_RectTileMap[row][col];}
        inline void SetRectTile(int row, int col, int tilesize) {m_RectTileMap[row][col] = {col*tilesize, row*tilesize, tilesize, tilesize};}
        void SetRectTileMap();

    private:
        Vector2D cam = Camera::GetInstance()->GetPosition();
        SDL_Rect m_RectTileMap[MAX_SIZE_MAP][MAX_SIZE_MAP];
        int m_NumRows, m_NumCols;


};

#endif // GAMEMAP_H
