#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
	double a;
	double b;

	cin >> a >> b;

	cout << fixed << setprecision(3);

	cout << a + b << endl;
	cout << a - b << endl;
	cout << a * b << endl;
	cout << a / b;
}
