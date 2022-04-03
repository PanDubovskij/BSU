#include "Rational.h"
int Gcd(int a, int b)
{
	while (a != b)
	{
		a > b ? a -= b : b -= a;
	}
	return a;
}

Rational::Rational(int a_, int b_) :a(a_), b(b_ != 0 ? b_ : 1) { }
Rational::Rational(const Rational& r) :a(r.a), b(r.b) {  }
long compare(const Rational& r, const Rational& r1)
{
	return (r.a * r1.b - r.b * r1.a);
	
}
Rational Rational::operator+(const Rational &r)//вызов конструктора
{
	Rational sum(a * r.b + b * r.a, b * r.b);
	sum.reduce();
	return sum;//вызов конструктора
}
Rational Rational::operator*(const Rational& r)
{
	Rational prod(a * r.a, b * r.b);
	prod.reduce();
	return prod;
}
Rational Rational::operator/(const Rational& r)
{
	Rational div(a * r.b, b * r.a);
	div.reduce();
	return div;
}
bool operator==(const Rational& r, const Rational&r1)
{
	return compare(r, r1)==0;
}
bool operator<(const Rational& r, const Rational& r1)
{
	return compare(r, r1) < 0;
}
bool operator>(const Rational& r, const Rational& r1)
{
	return compare(r, r1) > 0;
}

void Rational::reduce()
{
	int _gcd = Gcd(a, b);
	a /= _gcd;
	b /= _gcd;
}
std::ostream& operator<<(std::ostream& out, const Rational& r)
{
	if (r.b == 1) out << r.a << "\n";
	else
	out << r.a << "/" << r.b << "\n";
	return out;
}
