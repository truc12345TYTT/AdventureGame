#ifndef MAINCHARACTER_H
#define MAINCHARACTER_H

#include "Character.h"
#include "Animation.h"
#include "RigidBody.h"
#include "Point.h"
#include "Inputs.h"
#include <SDL_mixer.h>
#include <SDL.h>

class MainCharacter : public Character
{
    public:
        MainCharacter(Properties* props);

        virtual void Draw();
        virtual void Update(float dt);
        virtual void Clean();
        void Action(float dt);
        SDL_RendererFlip GetFlip(){return m_Flip;}

        inline Transform* GetTransform(){return m_Transform;}

        bool GetIsJumping();
        void Die();
        inline int GetDie(){return m_Die;}

    private:

        Animation* m_Animation;
        RigidBody* m_RigidBody;

        bool m_IsJumping;
        Mix_Chunk* m_JumpMusic;
        int m_Die;


};

#endif // MAINCHARACTER_H
