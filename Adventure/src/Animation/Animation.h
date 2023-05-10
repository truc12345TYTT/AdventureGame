#ifndef ANIMATION_H
#define ANIMATION_H

#include "SDL.h"
#include <string>

class Animation
{
    public:
        Animation(){};
        void SetProps (std::string _SpriteTextureID ,int _SpriteRow, int _AnimationSpeed, int _FrameCount, SDL_RendererFlip _SpriteFlip = SDL_FLIP_NONE);

        void Update();
        void Draw(float x, float y, int _SpriteWidth,int _SpriteHeight);

    private:
        std::string m_SpriteTextureID;
        SDL_RendererFlip m_SpriteFlip;

        int m_AnimationSpeed, m_FrameCount;
        int m_SpriteRow;

        int m_SpriteFrame;

};

#endif // ANIMATION_H
