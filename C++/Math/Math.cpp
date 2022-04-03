#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	double x, y, z, s, a, b, a3, b3; 
	cout << "Enter x, y, z\n";
	cin >> x >> y >> z;
	s = pow(abs(cos(x) - cos(y)), 1.0 + 2.0 * pow(sin(y), 2.0)) * (1.0 + z + (pow(z, 2.0) / 2.0) + (pow(z, 3.0) / 3.0) + (pow(z, 4.0) / 4.0));
	cout << s << endl;
	a = y + (pow(x, 3.0) / (pow(y, 2.0) + abs(x / (y + 3.0))));
	b = 1.0 + pow(tan(z), 2.0);
	cout << a << endl << b << endl;
	a3 = y + pow(x, 2.0 / 3.0) / (1.0 + pow(y, 2.0) + abs(pow(x, 2.0) / (y + pow(x, 3.0) / 3)));
	b3 = 1.0 + pow(tan(z / 2.0), 2.0);
	cout << a3 << endl << b3 << endl;
	return 0;
	system("pause");
}