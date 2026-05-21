#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	int a;
	int b;
	int c;

	double rectangleArea;
	double pathArea;
	double repeatedArea;

	cin >> a >> b >> c;

	rectangleArea = a * b;
	pathArea = c * b + c * a;
	repeatedArea = c * c;

	cout << rectangleArea - (pathArea - repeatedArea);

}