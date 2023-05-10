#ifndef MENU_H
#define MENU_H

#include <SDL_ttf.h>
#include <string>

class Menu
{
    public:
        static Menu* GetInstance(){return s_Instance = (s_Instance != nullptr)? s_Instance : new Menu();};
        bool Init();
        void Draw(std::string write, SDL_Rect srcRest, SDL_Rect desRect);
        void Update();

    private:
        TTF_Font* m_Font;
        Menu() {};
         static Menu* s_Instance;
};

#endif // MENU_H
