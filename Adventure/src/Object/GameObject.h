#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "IObject.h"
#include "Transform.h"
#include "Point.h"
#include <SDL.h>

struct Properties{

    public:
        Properties(std::string _TextureID, float _X, float _Y, int _Width, int _Height, SDL_RendererFlip _Flip = SDL_FLIP_NONE):
            TextureID(_TextureID), X(_X), Y(_Y), Width(_Width), Height(_Height), Flip(_Flip) {};

    public:
        std::string TextureID;
        float X, Y;
        int Width, Height;
        SDL_RendererFlip Flip;

};

class GameObject : public IObject
{
    public:
        GameObject(Properties* props): m_TextureID(props->TextureID), m_Width(props->Width), m_Height(props->Height), m_Flip(props->Flip) {
            m_Transform = new Transform(props->X, props->Y);
        };

        virtual void Draw()=0;
        virtual void Update(float dt)=0;
        virtual void Clean()=0;

    protected:
        std::string m_TextureID;
        Transform* m_Transform;
        int m_Width, m_Height;
        SDL_RendererFlip m_Flip;


};

#endif // GAMEOBJECT_H
