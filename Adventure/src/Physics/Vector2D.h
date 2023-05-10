#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <iostream>
#include <string>

class Vector2D
{
    public:
        float X, Y;

    public:
        Vector2D(float _X = 0, float _Y = 0): X(_X), Y(_Y) {};
        void Log(std::string msg = ""){std::cerr << msg << "(X Y) = (" << X << ' ' << Y << ')' << std::endl;}

    public:
        inline Vector2D operator+(const Vector2D& v) const {return Vector2D(X + v.X, Y + v.Y);};
        inline Vector2D operator-(const Vector2D& v) const {return Vector2D(X - v.X, Y - v.Y);};
        inline Vector2D operator*(const float& scalar) const {return Vector2D(X*scalar, Y*scalar);};

};

#endif // VECTOR2D_H
