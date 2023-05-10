#include "Menu.h"
#include "Game.h"

Menu* Menu::s_Instance = nullptr;

bool Menu::Init(){

     if (TTF_Init() < 0){
        SDL_Log("%s", TTF_GetError());
        return false;
    }

    m_Font = TTF_OpenFont("Font/Villa.ttf", 15);
    if (m_Font == nullptr) SDL_Log("%s\n", TTF_GetError());
    return true;
}


void Menu::Draw(std::string write, SDL_Rect srcRest, SDL_Rect desRect){

    SDL_Color fg = { 21, 21, 122};
    SDL_Surface* surface = TTF_RenderText_Solid(m_Font, write.c_str(), fg);

    SDL_Texture* texture = SDL_CreateTextureFromSurface(Game::GetInstance()->GetRenderer(), surface);
    SDL_FreeSurface(surface);

    TTF_SizeText(m_Font, write.c_str(), &srcRest.w, &srcRest.h);
    SDL_SetRenderDrawColor(Game::GetInstance()->GetRenderer(),242 , 165, 126, 0);
    SDL_RenderClear(Game::GetInstance()->GetRenderer());
    SDL_RenderCopy(Game::GetInstance()->GetRenderer(), texture, &srcRest, &desRect);
    SDL_RenderPresent(Game::GetInstance()->GetRenderer());
}

void Menu::Update(){
    SDL_RenderPresent(Game::GetInstance()->GetRenderer());
}
