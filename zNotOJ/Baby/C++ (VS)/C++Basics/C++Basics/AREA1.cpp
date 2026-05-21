#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	int a;

	cin >> a;

	cout << fixed << setprecision(2);

	cout << (sqrt(3) * pow(a, 2)) / 4 - (pow((((double)2 / 3 ) * (a * sqrt(3) / 2)) / 2, 2) * 3.14f);
}