#pragma once
#include <fstream>

namespace MyLib
{
    class Number
    {
    private:
        double number = 0.;
    public:
        Number() {
            number = 0.;
        };
        Number(double number);
        ~Number() {}

        double getDouble();

        Number& operator=(Number& n);
        Number operator+(const Number& n);
        Number operator-(const Number& n);
        Number operator*(const Number& n);
        Number operator/(const Number& n);

        friend std::ostream& operator<< (std::ostream&, const Number&);
        friend std::istream& operator>> (std::istream&, Number&);

        static double Add(double a, double b);
        static double Substract(double a, double b);
        static double Multiply(double a, double b);
        static double Divide(double a, double b);
    };

    const Number ZERO(0);
    const Number ONE(1);
    Number createNumber(double number);
}
