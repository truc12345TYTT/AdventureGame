#ifndef CHARACTER_H
#define CHARACTER_H

#include "GameObject.h"
#include "Vector2D.h"
#include "Point.h"
#include "Camera.h"

class Character : public GameObject
{
    public:
        Character(Properties* props) : GameObject(props) {};

        virtual void Draw()=0;
        virtual void Update(float dt)=0;
        virtual void Clean()=0;

        void SetIsMove(){
            int row = int((GetOrigin()->Y + Camera::GetInstance()->GetPosition().Y)/16);
            int col = int((GetOrigin()->X + Camera::GetInstance()->GetPosition().X)/16);

             if (m_TileValue[row + 1][col] || m_TileValue[row][col] ){
                m_IsMoveDown = false;
                m_IsGrounded = true;

            }
            else if (m_TileValue[row + 1][col] == 0|| m_TileValue[row][col] == 0) {
                m_IsGrounded = false;
            }
            if (m_TileValue[row - 1][col] || m_TileValue[row][col]){
                m_IsMoveUp = false;
            }
            if (m_TileValue[row][col - 1] || m_TileValue[row][col]){
                m_IsMoveLeft = false;
            }
            if (m_TileValue[row][col + 1] || m_TileValue[row][col]){
                m_IsMoveRight = false;
            }
        }

        inline void SetTileValue(int row, int col, int _TileValue){m_TileValue[row][col] = _TileValue;}
        inline Point* GetOrigin(){return m_Origin;}
        inline bool GetIsGround() {return m_IsGrounded; }

    protected:
        std::string m_Name;
        bool m_IsMoveUp,  m_IsMoveDown,  m_IsMoveLeft,  m_IsMoveRight;
        int m_TileValue[200][200];
        Point* m_Origin;

        bool m_IsGrounded;
};

#endif // CHARACTER_H
