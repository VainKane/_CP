#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

int tram;
int chuc;
int dv;

int hangNghin;
int hangTram;
int hangChuc;

int a;
int b;
int c;
int d;

int num;

int main()
{
	cin >> a >> b >> c >> d;

	num = a + b + c + d;

	hangNghin = num / 1000;

	tram = num - hangNghin * 1000;
	hangTram = tram / 100;

	chuc = tram - hangTram * 100;
	hangChuc = chuc / 10;

	dv = chuc - hangChuc * 10;

	cout << num << endl;
	cout << hangChuc << " " << dv;

}

	