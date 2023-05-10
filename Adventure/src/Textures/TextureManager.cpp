#include "TextureManager.h"
#include <SDL_image.h>
#include "Game.h"
#include "Camera.h"
#include "Vector2D.h"

#include <iostream>

TextureManager* TextureManager::s_Instance = nullptr;

bool TextureManager::Load(std::string id, std::string filename){

    SDL_Surface* loadedSurface = IMG_Load(filename.c_str());
    if (loadedSurface == nullptr){
        SDL_Log("Falied to load loadedSurface: %s\n", SDL_GetError());
        return false;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(Game::GetInstance()->GetRenderer(), loadedSurface);
    if (texture == nullptr){
        SDL_Log("Failed to load texture from surface: %s\n", SDL_GetError());
        return false;
    }

    m_TextureMap[id] = texture;
    return true;
}


void TextureManager::Draw(std::string id, int x, int y, int width, int height, SDL_RendererFlip flip){

    SDL_Rect srcRect = {0, 0, width, height};
    Vector2D cam = Camera::GetInstance()->GetPosition();
    SDL_Rect dstRect = {x - int(cam.X), y - int(cam.Y), width, height};

    SDL_RenderCopyEx(Game::GetInstance()->GetRenderer(), m_TextureMap[id], &srcRect, &dstRect, 0, nullptr, flip);
}

void TextureManager::DrawTileMap(std::string id, int terrainID, int x, int y, int tilesize, SDL_RendererFlip flip){
    SDL_Rect srcRect = { (terrainID%22)*tilesize,(terrainID/22)*tilesize, tilesize, tilesize};

    Vector2D cam = Camera::GetInstance()->GetPosition();
    SDL_Rect dstRect = {x - int(cam.X), y - int(cam.Y), tilesize, tilesize};
  //  std::cout << terrainID << ' ' << (terrainID%22)*tilesize << ' ' << (terrainID/22)*tilesize << ' ' << x << ' ' << y << std::endl;
    SDL_RenderCopyEx(Game::GetInstance()->GetRenderer(), m_TextureMap[id], &srcRect, &dstRect, 0, nullptr, flip);
}

void TextureManager::DrawFrame(std::string id, int x, int y, int width, int height, int row, int frame, SDL_RendererFlip flip){

    SDL_Rect srcRect = {width*frame, height*(row - 1), width, height};
    SDL_Rect dstRect = {x, y, width, height};

    SDL_RenderCopyEx(Game::GetInstance()->GetRenderer(), m_TextureMap[id], &srcRect, &dstRect, 0, nullptr, flip);
}

void TextureManager::DrawTile(std::string tilesetID, int tileSize, int x, int y, int row, int frame, SDL_RendererFlip flip){

    SDL_Rect srcRect = {tileSize*frame, tileSize*(row - 1), tileSize, tileSize};
    SDL_Rect dstRect = {x, y, tileSize, tileSize};

    SDL_RenderCopyEx(Game::GetInstance()->GetRenderer(), m_TextureMap[tilesetID], &srcRect, &dstRect, 0, nullptr, flip);
}

void TextureManager::Drop(std::string id){

    SDL_DestroyTexture(m_TextureMap[id]);
    m_TextureMap.erase(id);
}

void TextureManager::Clean(){

    std::map<std::string, SDL_Texture*>::iterator it;
    for (it = m_TextureMap.begin(); it != m_TextureMap.end(); it ++)
        SDL_DestroyTexture(it->second);

    m_TextureMap.clear();
}

