#include "number.h"

namespace MyLib
{
    Number::Number(double n)
    {
        number = n;
    }

    double Number::getDouble()
    {
        return this->number;
    }

    Number& Number::operator=(Number& n)
    {
        number = n.number;
        return (*this);
    }

    Number Number::operator+(const Number& n)
    {
        return Number(number + n.number);
    }

    Number Number::operator-(const Number& n)
    {
        return Number(number - n.number);
    }

    Number Number::operator*(const Number& n)
    {
        return Number(number * n.number);
    }

    Number Number::operator/(const Number& n)
    {
        return Number(number / n.number);
    }

    double Number::Add(double a, double b)
    {
        return a + b;
    }

    double Number::Substract(double a, double b)
    {
        return a - b;
    }

    double Number::Multiply(double a, double b)
    {
        return a * b;
    }

    double Number::Divide(double a, double b)
    {
        return a / b;
    }

    std::ostream& operator<<(std::ostream& out, const Number& n)
    {
        out << n.number;
        return out;
    }
    std::istream& operator>>(std::istream& in, Number& n)
    {
        in >> n.number;
        return in;
    }
    Number createNumber(double number)
    {
        return Number(number);
    }
}