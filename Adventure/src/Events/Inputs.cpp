#include "Inputs.h"
#include "Game.h"
#include <iostream>

Inputs* Inputs::s_Instance = nullptr;

Inputs::Inputs(){

    m_KeyStates = SDL_GetKeyboardState(nullptr);
}

void Inputs::Listen(){

    while (SDL_PollEvent(&m_Event)){
        switch(m_Event.type){
            case SDL_QUIT:       Game::GetInstance()->Quit();   break;
            case SDL_KEYDOWN:    KeyDown();                     break;
            case SDL_KEYUP:      KeyUp();                       break;
        }
    }
}

bool Inputs::GetKeyDown(SDL_Scancode key){

    return (m_KeyStates[key] == 1);
}

void Inputs::KeyUp(){

    m_KeyStates = SDL_GetKeyboardState(nullptr);
}

void Inputs::KeyDown(){

    m_KeyStates = SDL_GetKeyboardState(nullptr);
}


