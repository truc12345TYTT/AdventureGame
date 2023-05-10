#ifndef POINT_H
#define POINT_H

#include <string>
#include <iostream>

class Point
{
    public:
        float X, Y;

    public:
        Point(float _X = 0, float _Y = 0): X(_X), Y(_Y) {};
        void Log(std::string msg = ""){std::cerr << msg << "(X Y) = (" << X << ' ' << Y << ')' << std::endl;}

    public:
        inline Point operator+(const Point& v) const {return Point(X + v.X, Y + v.Y);};
        inline Point operator-(const Point& v) const {return Point(X - v.X, Y - v.Y);};
        inline Point operator*(const float& scalar) const {return Point(X*scalar, Y*scalar);};

};

#endif // POINT_H
