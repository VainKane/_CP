#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

double a;
double b;
double r = 0;

int main()
{
	cin >> a >> b;

	r = a / 2;

	cout << fixed << setprecision(2);

	cout << a * b - (3.14 * r * r);
}