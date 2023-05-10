#include "Timer.h"
#include <SDL.h>

Timer* Timer::s_Instance = nullptr;

void Timer::Tick(){

    m_DeltaTime = (SDL_GetTicks() - m_LastTime)*(TAGET_FPS/1000.0);

    if (m_DeltaTime > TAGET_DELTATIME)
        m_DeltaTime = TAGET_DELTATIME;

    m_LastTime = SDL_GetTicks();
}
