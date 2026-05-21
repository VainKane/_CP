#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

double a;
double b;
double c;
double d;

double r;

double height;
double totalArea;
double circleArea;

int main()
{
	cin >> a >> b >> c;

	d = (b - a) / 2;
	height = sqrt(c * c - d * d);
	r = 0.25 * height;

	circleArea = r * r * 3.14;

	totalArea = 0.5 * (a + b) * height;

	cout << fixed << setprecision(2);

	cout << totalArea - circleArea;

}