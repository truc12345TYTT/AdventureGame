#include "Game.h"
#include "Timer.h"
#include "Menu.h"
#include "Inputs.h"

#include <iostream>

using namespace std;

int main(int argc, char** args){

    Game::GetInstance()->Init();
    Menu::GetInstance()->Init();

    SDL_Rect src = {0, 0, 200, 50};
    SDL_Rect dst = {100, 500, src.w, src.h};
    Menu::GetInstance()->Draw("PRESS P TO PLAY",src, dst);

    Menu::GetInstance()->Update();

    while(Game::GetInstance()->IsRunning()){
        Game::GetInstance()->Events();
        if (Inputs::GetInstance()->GetKeyDown(SDL_SCANCODE_P)) break;
    }

    while(Game::GetInstance()->IsRunning() ){
        if (Game::GetInstance()->GetIsDie() == false) {
            Game::GetInstance()->Events();
            Game::GetInstance()->Update();
            Game::GetInstance()->Render();
            Timer::GetInstance()->Tick();
        }
        else{
            SDL_Rect src = {0, 0, 200, 50};
            SDL_Rect dst = {400, 400, src.w, src.h};
            Menu::GetInstance()->Draw("YOU LOSE!",src, dst);
            SDL_Delay(5000);
        }
    }


    Game::GetInstance()->Clean();
    return 0;
}
