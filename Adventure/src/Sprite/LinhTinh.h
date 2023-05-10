#ifndef LINHTINH_H
#define LINHTINH_H

#include "Character.h"
#include "Animation.h"

class LinhTinh : public Character
{
    public:
        LinhTinh(Properties* props);
        virtual void Draw();
        virtual void Update(float dt);
        virtual void Clean();

    private:
        bool m_IsWin;
        bool m_IsFruit;
        Animation* m_Animation;
};

#endif // LINHTINH_H
