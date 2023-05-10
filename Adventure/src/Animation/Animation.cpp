#include "Animation.h"
#include "TextureManager.h"


void Animation::SetProps(std::string _SpriteTextureID ,int _SpriteRow, int _AnimationSpeed, int _FrameCount, SDL_RendererFlip _SpriteFlip ){

    m_SpriteTextureID = _SpriteTextureID;
    m_SpriteRow       = _SpriteRow;
    m_AnimationSpeed  = _AnimationSpeed;
    m_FrameCount      = _FrameCount;
    m_SpriteFlip      = _SpriteFlip;
}

void Animation::Update(){


    m_SpriteFrame = (SDL_GetTicks()/m_AnimationSpeed)%m_FrameCount;
}

void Animation::Draw(float x, float y, int _SpriteWidth,int _SpriteHeight){

  //  if (m_SpriteFlip == SDL_FLIP_HORIZONTAL) SDL_Log("succes HO!\n");
    TextureManager::GetInstance()->DrawFrame(m_SpriteTextureID, x, y, _SpriteWidth, _SpriteHeight, m_SpriteRow, m_SpriteFrame, m_SpriteFlip);
}
