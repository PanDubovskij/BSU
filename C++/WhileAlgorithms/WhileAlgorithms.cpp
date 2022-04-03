#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	{ //задание 1
		int n;
		cout << "Enter n" << endl;
		cin >> n;
		while (n % 2 == 0)
		{
			n /= 2;
		}
		if (n == 1)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	{
		//задание 2
		int n;
		cout << "enter n" << endl;
		cin >> n;
		for (int i = 2; i < n; i++) { cout << "1/" << i << endl; }
		for (int i = 2; i < n; i++) {
			for (int j = 1; j < i; j++) {
				if (i % j != 0) { cout << j << "/" << i << endl; }
			}
		}
	}
	{
		//Задание 3
		int n;
		int summa = 0;
		cout << "enter n" << endl;
		cin >> n;
		while (n != 0)
		{
			summa += n % 10;
			n /= 10;
		}
		cout << summa << endl;

	}
	{
		//задание 4
		size_t day, month, year, helpDay, previousDay;
		enum Months { Jan = 1, Feb, Mar, Apr, May, June, July, Aug, Sep, Oct, Nov, Dec };
		cout << "Enter day, month, year" << endl;
		cin >> day >> month >> year;
		switch (month)
		{
		case May: case July: case Oct: case Dec:
			helpDay = 31; previousDay = 30;
			break;
		case Jan: case Aug:
			helpDay = 31; previousDay = 31;
			break;
		case Apr: case June: case Sep: case Nov:
			helpDay = 30; previousDay = 31;
			break;
		case Mar: helpDay = 31; (year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0) ? previousDay = 29 : previousDay = 28;
			break;
		case Feb:
			(year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0) ? helpDay = 29 : helpDay = 28; previousDay = 31;
			break;
		}
		if ((day < helpDay) && (day != 1))
			day--;
		else if ((day == 1) && (month != 1))
		{
			day = previousDay;
			month--;
		}
		else if ((day == 1) && (month == 1))
		{
			day = previousDay;
			month = 12;
			year--;
		}
		cout << " Yesterday " << day << "." << month << "." << year << endl;


	}
	{
		//задание 5
		int fact;
		int n;
		double summa;
		int i;
		cout << "Enter n" << endl;
		cin >> n;
		summa = 1;
		fact = 1;
		i = 1;
		while (i <= n)
		{
			fact *= i;
			summa += 1.0 / fact;
			i++;
		}
		cout << summa << endl; // сумма будет стремиться к экспоненте
	}


	system("pause");
	return 0;
}