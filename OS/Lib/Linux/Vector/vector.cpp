#include <math.h>
#include "vector.h"

namespace MyLib
{

    Vector::Vector(Number x, Number y)
    {
        _x = x;
        _y = y;
    }
    Number Vector::getX()
    {
        return Number(_x);
    }
    Number Vector::getY()
    {
        return Number(_y);
    }
    Vector& Vector::operator=(Vector& v)
    {
        _x = v._x;
        _y = v._y;
        return (*this);
    }
    Vector Vector::operator+(const Vector& v)
    {
        return Vector(_x + v._x, _y + v._y);
    }
    Number Vector::Radius()
    {
        return Number(sqrt(_x.getDouble()* _x.getDouble()+ _y.getDouble()*_y.getDouble()));
    }
    Number Vector::Angle()
    {
        return Number(asin(_y.getDouble()/Radius().getDouble()));
    }
    std::ostream& operator<<(std::ostream& out, const Vector& v)
    {
        out << v._x << v._y;
        return out;
    }
    std::istream& operator>>(std::istream& in, Vector& v)
    {
        in >> v._x >> v._y;
        return in;
    }
}