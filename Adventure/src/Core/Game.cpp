#include "Game.h"
#include "TextureManager.h"
#include "MainCharacter.h"
#include "Inputs.h"
#include "Timer.h"
#include "GameMap.h"
#include "Camera.h"
#include <iostream>

#define SIZE_MAIN 32

Game* Game::s_Instance = nullptr;
MainCharacter* player = nullptr;

GameMap* g_Map = nullptr;
GameMap* g_Trap = nullptr;

bool Game::Init(){

    if (SDL_Init(SDL_INIT_VIDEO) && IMG_Init(IMG_INIT_PNG)){
        SDL_Log("Failed to initialize SDL: %s\n", SDL_GetError());
        return false;
    }

    SDL_WindowFlags flags = SDL_WindowFlags(SDL_WINDOW_ALLOW_HIGHDPI | SDL_WINDOW_RESIZABLE);
    m_Window = SDL_CreateWindow("Adventure", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, flags);
    if (m_Window == nullptr){
        SDL_Log("Failed to create Window: %s\n", SDL_GetError());
        return false;
    }

    m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (m_Renderer == nullptr){
        SDL_Log("Failed to create Renderer: %s\n", SDL_GetError());
        return false;
    }

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) == -1){
        SDL_Log("Mixer Error: %s\n", Mix_GetError());
    }


    m_GameMusic = Mix_LoadMUS("Music/funny-and-comical-melody-glide-synth-bass-and-trumpet-21398.mp3");
    if (m_GameMusic == nullptr) std::cout << Mix_GetError();
    Mix_PlayMusic(m_GameMusic, -1);

   /* if (!TextureManager::GetInstance()->Load("player", "assets/Main Characters/Mask Dude/Idle (32x32).png" || )){
        SDL_Log("Failed to Load TextureManager: %s\n", SDL_GetError());
        return false;
    }
    else SDL_Log("Load Texture: Done!\n"); */
    LoadMainCharacter();
    TextureManager::GetInstance()->Load("MAP", "assets/Terrain/Terrain (16x16).png");
    TextureManager::GetInstance()->Load("BG", "assets/Maps/Background01.png");
    TextureManager::GetInstance()->Load("TRAP","assets/Traps/Spikes/Idle.png");
    ///-------------------------------------------------
    g_Map = new GameMap("Maps/Map01.map");
    g_Map->ReadFile();
    g_Trap = new GameMap("Maps/Trap01.map");
    g_Trap->ReadFile();

    for (int i = 0; i < g_Map->GetNumRow(); i ++){
        for (int j = 0; j < g_Map->GetNumCol(); j++){
            player->SetTileValue(i, j, g_Map->GetValue(i,j));
        }
    }
    ///--------------------------------------------------


    Camera::GetInstance()->SetTarget(player->GetOrigin());

    return m_IsRunning = true;
}

void Game::LoadMainCharacter(){
    TextureManager::GetInstance()->Load("player", "assets/Main Characters/Pink Man/Idle (32x32).png");
    TextureManager::GetInstance()->Load("player_run", "assets/Main Characters/Pink Man/Run (32x32).png");
    TextureManager::GetInstance()->Load("player_fall", "assets/Main Characters/Pink Man/Fall (32x32).png");
    TextureManager::GetInstance()->Load("player_jump", "assets/Main Characters/Pink Man/Jump (32x32).png");
    TextureManager::GetInstance()->Load("player_wall_jump", "assets/Main Characters/Pink Man/Wall Jump (32x32).png");
    TextureManager::GetInstance()->Load("player_double_jump", "assets/Main Characters/Pink Man/Double Jump (32x32).png");
    TextureManager::GetInstance()->Load("player_hit", "assets/Main Characters/Pink Man/Hit (32x32).png");

    player = new MainCharacter(new Properties("player", 300, 200, SIZE_MAIN, SIZE_MAIN));

}



void Game::Update(){

    float dt = Timer::GetInstance()->GetDeltaTime();

    player->Update(dt);
    int row = int((player->GetOrigin()->Y + Camera::GetInstance()->GetPosition().Y)/16);
    int col = int((player->GetOrigin()->X + Camera::GetInstance()->GetPosition().X)/16);
    if (g_Trap->GetValue(row, col)){
        player->Die();
    }
    std::cout << player->GetDie() <<std::endl;
    if (player->GetDie() > 100){
        m_IsDie = true;
    }
    else m_IsDie = false;

    Camera::GetInstance()->Update(dt);

}

void Game::Render(){

    float dt = Timer::GetInstance()->GetDeltaTime();
    SDL_SetRenderDrawColor(m_Renderer,242 , 165, 126, 0);
    SDL_RenderClear(m_Renderer);
    TextureManager::GetInstance()->Draw("BG", 0, 0, 80*16, 45*16);

    g_Trap->Draw("TRAP");
    g_Map->Draw("MAP");

    if (player->GetIsJumping() ){
        for (int i = 0; i < 25; i ++){ player->GetTransform()->Y += -4;
            SDL_RenderClear(m_Renderer);
    TextureManager::GetInstance()->Draw("BG", 0, 0, 80*16, 45*16); player->Update(dt); Camera::GetInstance()->Update(dt);
    g_Map->Draw("MAP"); g_Trap->Draw("TRAP");  player->Draw(); SDL_RenderPresent(m_Renderer);}
    }

    player->Draw();
    SDL_RenderPresent(m_Renderer);
}

void Game::Events(){

    Inputs::GetInstance()->Listen();
}

void Game::Clean(){

    TextureManager::GetInstance()->Clean();

    SDL_DestroyRenderer(m_Renderer);
    SDL_DestroyWindow(m_Window);

    IMG_Quit();
    SDL_Quit();
    Mix_Quit();

    SDL_Log("Clean: Done!\n");
}

void Game::Quit(){

    m_IsRunning = false;
}
