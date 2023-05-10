#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>


#define SCREEN_WIDTH 960
#define SCREEN_HEIGHT 640

class Game
{

    public:
        static Game* GetInstance(){return s_Instance = (s_Instance != nullptr)? s_Instance : new Game();};

        bool Init();
        void LoadMainCharacter();


        void Clean();
        void Update();
        void Render();
        void Events();
        void Quit();

        inline bool IsRunning(){return m_IsRunning;};
        inline SDL_Renderer* GetRenderer(){return m_Renderer;};

        inline bool GetIsDie(){return m_IsDie;}

    private:
        Game(){};

        SDL_Window* m_Window;
        SDL_Renderer* m_Renderer;

        Mix_Music* m_GameMusic;
        TTF_Font* m_Font;

        bool m_IsRunning;
        static Game* s_Instance;

        bool m_IsDie;
};

#endif // GAME_H
