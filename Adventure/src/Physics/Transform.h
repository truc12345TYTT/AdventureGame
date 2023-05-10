#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <iostream>
#include <string>
#include "Vector2D.h"

class Transform
{
    public:
        float X, Y;

    public:
        Transform(float _X = 0, float _Y = 0): X(_X), Y(_Y) {};
        void Log(std::string msg = ""){std::cerr << msg << "(X Y) = (" << X << ' ' << Y << ')' << std::endl;}

    public:
        inline void TranslateX(float x){X += x;}
        inline void TranslateY(float y){Y += y;}
        inline void Translate(Vector2D v){X += v.X; Y += v.Y;}

};

#endif // TRANSFORM_H
