#include <iostream>
#include <string>
using namespace std;
int main() {

	{
		/*
		Узнайте имя пользователя и поприветствовуйте его.
    Выведите на экран строку “What’s your name”. После того, как пользователь введет 
    свое имя (например, Sasha), выведите: «Nice to meet you, Sasha”
		*/
		cout << "What’s your name\n";
		string text;
		cin >> text;
		cout << "Nice to meet you," << text << endl;
	}
	{
		//Выполните арифметические операции с двумя целыми числами x и y
		cout << "Enter x and y" << endl;
		int x, y;
		cin >> x >> y;
		cout << x << "+" << y << "=" << x + y << endl;
		cout << x << "-" << y << "=" << x - y << endl;
		cout << x << "*" << y << "=" << x * y << endl;
		cout << x << "/" << y << "=" << x / y << endl;
	}
	{
		//Поменяйте местами значения переменных x и y.
		cout << "Enter x and y" << endl;
		int x, y;
		cin >> x >> y;
		cout << y << " " << x << endl;
	}
	{
		//Для заданных х и у посчитайте значение выражения
		cout << "Enter x and y" << endl;
		int x, y;
		cin >> x >> y;
		float c;
		c = (float)(3 + x * x - y * y * y) * (x + 3) * (x + 3) / (x - y * y);
		cout << c << endl;
	}
	{
		//С начала года прошло m секунд. Определите который сейчас час (в минутах, 
	  //дробная часть игнорируется).
		cout << "Enter m" << endl;
		int m;
		cin >> m;
		cout << (m - (m / (3600 * 24)) * 3600 * 24) / 60 << endl;
	}
	{
		//задание 6a
		cout << "Enter a" << endl;
		double a, a1, a2;
		cin >> a;
		a1 = a * a;
		a2 = a1 * a1;
		cout << a2 << endl;
	}
	{
		//задание 6б
		cout << "Enter a" << endl;
		double a, a1, a2, a3;
		cin >> a;
		a1 = a * a;
		a2 = a1 * a1;
		a3 = a1 * a2;
		cout << a3 << endl;
	}
	{
		//задание 6в
		cout << "Enter a" << endl;
		double a, a1, a2, a3;
		cin >> a;
		a1 = a * a;
		a2 = a1 * a1;
		a3 = a1 * a2 * a; 
		cout << a3 << endl;
	}
	{
		//задание 6г
		cout << "Enter a" << endl;
		double a, a1, a2, a3;
		cin >> a;
		a1 = a * a;
		a2 = a1 * a1;
		a3 = a2 * a2;
		cout << a3 << endl;
	}
	{
		//задание 6д
		cout << "Enter a" << endl;
		double a, a1, a2, a3;
		cin >> a;
		a1 = a * a;
		a2 = a1 * a1;
		a3 = a2 * a2 * a;
		cout << a3 << endl;
	}
	{
		//задание 6е
		cout << "Enter a" << endl;
		double a, a1, a2, a3;
		cin >> a;
		a1 = a * a;
		a2 = a1 * a1;
		a3 = a2 * a2 * a1; 
		cout << a3 << endl;
	}
	{
		//задание 6ж
		cout << "Enter a" << endl;
		double a, a1, a2, a3;
		cin >> a;
		a1 = a * a;
		a2 = a1 * a1;
		a3 = a2 * a2 * a2 * a;
		cout << a3 << endl;
	}
	{
		//задание 6з
		cout << "Enter a" << endl;
		double a, a1, a2, a3, a4;
		cin >> a;
		a1 = a * a * a;
		a2 = a1 * a1;
		a3 = a2 * a2;
		a4 = a3 * a1; 
		cout << a4 << endl;
	}
	{
		//задание 6и
		cout << "Enter a" << endl;
		double a, a1, a2, a3, a4;
		cin >> a;
		a1 = a * a * a;
		a2 = a1 * a1;
		a3 = a2 * a2;
		a4 = a2 * a3 * a1; 
		cout << a4 << endl;
	}
	{
		//задание 6к
		cout << "Enter a" << endl;
		double a, a1, a2, a3, a4, a5;
		cin >> a;
		a1 = a * a;
		a2 = a1 * a1;
		a3 = a2 * a2 * a2;
		a4 = a3 * a3;
		a5 = a4 * a2; 
		cout << a5 << endl;
	}
	{
		//задание 6л
		cout << "Enter a" << endl;
		double a, a1, a2, a3, a4, a5;
		cin >> a;
		a1 = a * a;
		a2 = a1 * a1;
		a3 = a2 * a2;
		a4 = a3 * a3;
		a5 = a4 * a4 * a4;
		cout << a5 << endl;
	}
	{
		/*
		Дано вещественное число x. Не пользуясь никакими другими 
    арифметическими действиями кроме сложения, вычитания и умножения 
    вычислить выражения:
		*/
		cout << "Enter x" << endl;
		double x;
		cin >> x;
		cout << x * (4 * x * x + 3 * x + 2) + 1 << endl;
		cout << -x * (4 * x * x - 3 * x + 2) + 1 << endl;
	}

	system("pause");
	return 0;
}