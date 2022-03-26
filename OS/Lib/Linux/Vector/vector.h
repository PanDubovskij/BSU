#pragma once
#include <fstream>
#include "/home/jan/CLionProjects/Number/number.h"

namespace MyLib
{
    class Vector
    {
    private:
        Number _x=ZERO;
        Number _y=ZERO;
    public:
        Vector() {};
        Vector(Number x, Number y);
        ~Vector() {};

        Number getX();
        Number getY();

        Vector& operator=(Vector& v);
        Vector operator+(const Vector& v);

        Number Radius();
        Number Angle();

        friend std::ostream& operator<< (std::ostream& out, const Vector& v);
        friend std::istream& operator>> (std::istream& in, Vector& v);
    };

    const Vector ZERO_V(0,0);
    const Vector ONE_V(1,1);
}
