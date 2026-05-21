#include <iostream>
#include <cmath>
#include <string>

using namespace std;

unsigned int antenna;
unsigned int camera;

string type;

bool isType1;
bool isType2;
bool isType3;

int main()
{

	cin >> antenna >> camera;

	if (antenna >= 3 && camera <= 4)
	{
		isType1 = true;
	}
	if (antenna <= 6 && camera >= 2)
	{
		isType2 = true;
	}
	if (antenna <= 2 && camera <= 3)
	{
		isType3 = true;
	}

	if (isType1 == true)
	{
		type = "1";

		if (isType2 == true)
		{
			type += " 2";
		}
		if (isType3 == true)
		{
			type += " 3";
		}

		isType2 == false;
		isType3 == false;
	}

	else if (isType2 == true)
	{
		type = "2";

		if (isType3 == true)
		{
			type += " 3";
		}

		isType3 == false;
	}

	else if (isType3 == true)
	{
		type = "3";
	}

	else
	{
		type = "0";
	}

	cout << type;
}