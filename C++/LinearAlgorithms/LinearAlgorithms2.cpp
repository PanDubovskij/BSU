#include <iostream>
#include <cmath>
/*
4. Даны координаты двух различных полей шахматной доски x1, y1, x2, y2 (целые числа, лежащие в диапазоне 1–8). Проверить истинность высказывания: «Король за один ход может перейти с одного поля на другое».
4. Известны углы α и β у основания трапеции. Выяснить, если это возможно, тип трапеции (прямоугольная, равнобедренная, прямоугольник).
1. Дано целое число в диапазоне от 100 до 999. Вывести строку —словесное описание данного числа, например: 256 — "двести пятьдесят шесть", 814 — "восемьсот четырнадцать".
2. В восточном календаре принят 60-летний цикл, состоящий из 12-летних подциклов, обозначаемых названиями цвета: зеленый, красный, желтый, белый и черный. В каждом подцикле годы носят названия животных: крысы, коровы, тигра, зайца, дракона, змеи, лошади, овцы, обезьяны, курицы, собаки и свиньи. По номеру года вывести его название, если 1984 год был началом цикла— годом зеленой крысы.
3. Написать программу, которая вычисляет дату следующего дня.

*/
int main()
{
	{
		//задание 1
		setlocale(0, "");
		std::cout << "Введите координаты двух различных полей шахматной доски" << std::endl;
		int x1, y1, x2, y2;
		std::cin >> x1 >> y1 >> x2 >> y2;
		if ((x1>8)||(x2>8)||(y1>8)||(y2>8)|| (x1 <1) || (x2 <1) || (y1 <1) || (y2 <1)) { std::cout << "Неправильно введены данные" << std::endl; }
		else if ((abs(x1 - x2) < 2) && (abs(y1 - y2) < 2)) { std::cout << "Истина" << std::endl; }
		else { std::cout << "Ложь" << std::endl; }
	}
	{
		//задание 2
		setlocale(0, "");
		std::cout << "Введите углы трапеции" << std::endl;
		int a, b;
		std::cin >> a >> b;
		if ((a > 180) || (b > 180)) { std::cout << "Углы введены неправильно" << std::endl; }
		else if (((a == 90)&&(b!=90)) || ((b == 90)&&(a!=90))) { std::cout << "Трапеция прямоугольная" << std::endl; }
		else if ((a==b)&&(a!=90)&&(b!=90)) { std::cout << "Трапеция равнобедренная" << std::endl; }
		else if ((a == 90) && (b == 90)) { std::cout << "Прямоугольник" << std::endl; }
		else { std::cout << "Трапеция произвольная" << std::endl; }
	}
	{
		//задание 3
		setlocale(0, "");
		std::cout << "Введите число от 100 до 999" << std::endl;
		int a, a1, a2, a3, a4;
		std::cin >> a;
		a1 = a / 100;
		switch (a1)
		{
		case 1: std::cout << "Сто ";
			break;
		case 2: std::cout << "Двести ";
			break;
		case 3: std::cout << "Триста ";
			break;
		case 4: std::cout << "Четыреста ";
			break;
		case 5: std::cout << "Пятьсот ";
			break;
		case 6: std::cout << "Шестьсот ";
			break;
		case 7: std::cout << "Семьсот ";
			break;
		case 8: std::cout << "Восемьсот ";
			break;
		case 9: std::cout << "Девятьсот ";
			break;
		}
		a2 = a % 100;
		switch (a2)
		{
		case 11: std::cout << "одиннадцать ";
			break;
		case 12: std::cout << "двенадцать ";
			break;
		case 13: std::cout << "тринадцать ";
			break;
		case 14: std::cout << "четырнадцать ";
			break;
		case 15: std::cout << "пятнадцать ";
			break;
		case 16: std::cout << "шестнадцать ";
			break;
		case 17: std::cout << "семнадцать ";
			break;
		case 18: std::cout << "восемнадцать ";
			break;
		case 19: std::cout << "девятнадцать ";
			break;
		}
		a3 = a / 10 - a1 * 10;
		switch (a3)
		{
		case 2: std::cout << "двадцать ";
			break;
		case 3: std::cout << "тридцать ";
			break;
		case 4: std::cout << "сорок ";
			break;
		case 5: std::cout << "пятьдесят ";
			break;
		case 6: std::cout << "шестьдесят ";
			break;
		case 7: std::cout << "семьдесят ";
			break;
		case 8: std::cout << "восемьдесят ";
			break;
		case 9: std::cout << "девяносто ";
			break;
		}
		a4 = a % 10;
		if (a3 != 1) {
			switch (a4)
			{
			case 1: std::cout << "один\n ";
				break;
			case 2: std::cout << "два\n ";
				break;
			case 3: std::cout << "три\n";
				break;
			case 4: std::cout << "четыре\n";
				break;
			case 5: std::cout << "пять\n";
				break;
			case 6: std::cout << "шесть\n";
				break;
			case 7: std::cout << "семь\n";
				break;
			case 8: std::cout << "восемь\n";
				break;
			case 9: std::cout << "девять\n";
				break;
			}
		}
	}
		{
			//задание 4
		setlocale(0, "");
		std::cout << "Введите год" << std::endl;
		int year, colour, animal;
		std::cin >> year;
		if (year > 1983) { year = (year - 1984) % 60; }
		else { year = 60 - (1984 - year) % 60; }
		colour = year%10/2+1;
			switch (colour)
			{
			case 1: std::cout << "Год зелён";
				break;
			case 2: std::cout << "Год красн";
				break;
			case 3: std::cout << "Год желт";
				break;
			case 4: std::cout << "Год бел";
				break;
			case 5: std::cout << "Год чёрн";
				break;
			}
		animal = year % 12;
		switch (animal)
		{
		case 0: std::cout << "ой крысы";
			break;
		case 1: std::cout << "ой коровы";
			break;
		case 2: std::cout << "ого тигра";
			break;
		case 3: std::cout << "ого зайца";
			break;
		case 4: std::cout << "ого дракона";
			break;
		case 5: std::cout << "ой змеи";
			break;
		case 6: std::cout << "ой лошади";
			break;
		case 7: std::cout << "ой овцы";
			break;
		case 8: std::cout << "ой обезьяны";
			break;
		case 9: std::cout << "ой курицы";
			break;
		case 10: std::cout << "ой собаки";
			break;
		case 11: std::cout << "ой свиньи";
			break;
		}

		}
		{
			//задание 5
			size_t day, month, year, helpDay;
			enum Months { Jan = 1, Feb, Mar, Apr, May, June, July, Aug, Sep, Oct, Nov, Dec };
			std:: cout << "\nEnter day, month, year" << std::endl;
			std::cin >> day >> month >> year;
			switch (month)
				{
				case Jan:case Mar:case May:case July: case Aug: case Oct: case Dec:
					helpDay = 31;
					break;
				case Apr:case June: case Sep: case Nov:
					helpDay = 30;
					break;
				case Feb:
					(year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0) ? helpDay = 29 : helpDay = 28;
					break;
				}
			if (day < helpDay)
				day++;
			else if ((day == helpDay) && (month != 12))
			{
				day = 1;
				month++;
			}
			else
			{
				day = 1;
				month = 1;
				year++;
			}
			std::cout << "Завтра  " << day << "." << month << "." << year << std::endl;
		}
		system("pause");
		return 0;
	}