#ifndef INPUTS_H
#define INPUTS_H

#include <SDL.h>
#include <string>

class Inputs
{
    public:
        static Inputs* GetInstance() {return s_Instance = (s_Instance != nullptr)? s_Instance : new Inputs(); }

        void Listen();
        bool GetKeyDown(SDL_Scancode key);

        inline SDL_Event GetEvent(){return m_Event;}


    private:
        static Inputs* s_Instance;

        Inputs();
        void KeyUp();
        void KeyDown();

        SDL_Event m_Event;
        const Uint8* m_KeyStates;

};

#endif // INPUTS_H
