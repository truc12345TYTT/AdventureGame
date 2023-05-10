#ifndef RIGIDBODY_H
#define RIGIDBODY_H

#include "Vector2D.h"
#include <string>

#define UNI_MASS 1.0f
#define GRAVITY 8.9f

#define UP -1
#define DOWN 1
#define LEFT -1
#define RIGHT 1

class RigidBody
{
    public:
        RigidBody() { m_Mass = UNI_MASS; m_Gravity = GRAVITY;}

        inline void SetMass(float _Mass) {m_Mass = _Mass;}
        inline void SetGravity(float _Gravity) {m_Gravity = _Gravity;}

        inline Vector2D GetPosition(){return m_Position;}

        inline void Log(std::string msg = "") {std::cerr << msg << "(X Y) = (" << m_Position.X << ' ' << m_Position.Y << ')' << std::endl;}

    public:
        inline void ApplyForce(Vector2D F) {m_Force = F;}
        inline void ApplyForceX(float Fx) {m_Force.X = Fx;}
        inline void ApplyForceY(float Fy) {m_Force.Y = Fy;}
        inline void UnSetForce() {m_Force = Vector2D(0,0);}

        inline void ApplyFriction(Vector2D F) {m_Friction = F;}
        inline void UnSetFriction() {m_Friction = Vector2D(0,0);}

        inline void ApplyVelocityY(float Vy){m_Velocity.Y = Vy;}

        void Update(float dt){
            m_Accelaration.Y = m_Gravity + (m_Force.Y + m_Friction.Y)/m_Mass;
            m_Accelaration.X = (m_Force.X + m_Friction.X)/m_Mass;

            m_Velocity = m_Accelaration*dt;

            m_Position = m_Velocity*dt;
        }

    private:
        float m_Mass, m_Gravity;

        Vector2D m_Force, m_Friction;

        Vector2D m_Position, m_Velocity, m_Accelaration;

};

#endif // RIGIDBODY_H
