#include <iostream>
#include <cmath>

int main()
{
	{ //задание 1
		std::cout << "Enter n" << std::endl;
		int n, count = 0;
		std::cin >> n;
		for (int i0 = 11; count <= n; ++i0)
		{
			int i = i0; int  m = 0; int k = 0; int i2 = i * i;
			while (i != 0)
			{
				m *= 10;
				m += i % 10;
				i = i / 10;
			}
			while (i2 != 0)
			{
				k *= 10;
				k += i2 % 10;
				i2 = i2 / 10;

			}
			if ((m == i0) && (k == i0 * i0)) {
				std::cout << i0 << std::endl;
				count++;
				continue;
			}
		}
	}
	{
		//задание 2
		std::cout << "Enter a,b" << std::endl;
		int a, b;
		std::cin >> a >> b;
		if (b < 2) {
			std::cout << "There are no prime numbers in this interval" << std::endl;
		}
		else if (b < 3)
		{
			std::cout << 2 << std::endl;
		}
		else if ((b < 4) && (a <= 3))
		{
			std::cout << 2 << std::endl << 3 << std::endl;
		}
		else
		{
			std::cout << 2 << "\n" << 3 << std::endl;
			for (int i = a; i <= b; i++)
			{
				for (int j = 2; j < i; j++)
				{

					if ((i % j == 0) || (i % 3 == 0))
					{
						break;
					}
					else
					{
						std::cout << i << std::endl;
						break;
					}
				}
			}
		}
	}
	{//задание 3
		int a, b, c;
		std::cout << "Enter a\n";
		std::cin >> a;
		b = a;
		for (int i = 0; i < 10; i++)
		{
			c = 0;
			a = b;
			while (a > 0)
			{
				if (a % 10 == i)c++;
				a /= 10;
			}

			if (c == 1)
			{
				std::cout << "They are different" << std::endl;
				break;
			}
			else
			{
				std::cout << "They aren't different" << std::endl;
				break;
			}
		}
	}
	{//задание 4
		int a, b, c, numbers = 0;
		std::cout << "Enter a\n";
		std::cin >> a;
		b = a;

		for (; a > 0; numbers++)
		{
			a /= 10;
		}
		int firstnumb = (b / (pow(10, numbers - 1)));
		a = b;
		for (int i = 9; i != 0; i--)
		{
			c = 0;
			a = b;
			while (a > 0)
			{
				if (a % 10 == i)c++;
				a /= 10;
			}
			if (c % 2 == 1)
			{
				if (firstnumb > i)
				{

					int stepen = pow(10, numbers + 1);
					b = i * stepen + b;
					numbers++;
					continue;
				}
				else
				{
					b = b * 10 + i;
					continue;
				}
				continue;
			}
		}
		std::cout << b << std::endl;

	}
	{//задание 5
		double n = 1;
		double x, e;
		std::cout << "enter x from -1 to 1\n";
		std::cin >> x;
		std::cout << "Enter e\n";
		std::cin >> e;
		double res = 0; double a = -x;
		do
		{
			res += a;
			n++;
			a = -x*x / n;

		} while (abs(a) > e);
		std::cout << res << std::endl;
		std::cout << log(1 - x) << std::endl;

	}
	system("pause");
	return 0;
}
