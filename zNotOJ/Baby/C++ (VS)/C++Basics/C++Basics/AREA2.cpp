#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	double a;

	double triangleHeight;
	double triangleArea;
	double circleArea;

	cin >> a;

	triangleHeight = (a * sqrt(3)) / 2;
	triangleArea = 0.5 * triangleHeight * a;
	circleArea = pow(triangleHeight * ((double)2 / 3), 2) * 3.14f;

	cout << fixed << setprecision(2);

	cout << circleArea - triangleArea;

}