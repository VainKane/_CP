#include <iostream>
#include <cmath>
#include <string>

void Check(int num, int x, int y, std::string& resultOut);
void PairCheck(std::string aCheck, std::string bCheck, std::string& resultOut);

unsigned int a;
unsigned int b;
unsigned int c;

unsigned int x;
unsigned int y;

std::string aCheck;
std::string bCheck;
std::string cCheck;

std::string result = "KHONG";

int main()
{
	std::cin >> a >> b >> c >> x >> y;

	Check(a, x, y, aCheck);
	Check(b, x, y, bCheck);
	Check(c, x, y, cCheck);

	//std::cout << aCheck;
	//std::cout << bCheck;
	//std::cout << cCheck;

	PairCheck(aCheck, bCheck, result);
	PairCheck(bCheck, cCheck, result);
	PairCheck(cCheck, aCheck, result);

	std::cout << result;
}


void Check(int num, int x, int y, std::string& resultOut)
{
	if (num < x)
	{
		resultOut = "x";

		if (num < y)
		{
			resultOut += "y";
		}
	}
	else
	{
		if (num < y)
		{
			resultOut = "y";
		}
		else
		{
			resultOut = "0";
		}
	}
}

void PairCheck(std::string aCheck, std::string bCheck, std::string& resultOut)
{
	if (aCheck + bCheck == "xy")
	{
		resultOut = "CO";
	}
	else if (aCheck + bCheck == "yx")
	{
		resultOut = "CO";
	}
	else if (aCheck + bCheck == "xyxy")
	{
		resultOut = "CO";
	}
	else if (aCheck + bCheck == "xyx")
	{
		resultOut = "CO";
	}
	else if (aCheck + bCheck == "xyy")
	{
		resultOut = "CO";
	}
	else if (aCheck + bCheck == "xxy")
	{
		resultOut = "CO";
	}
	else if (aCheck + bCheck == "yxy")
	{
		resultOut = "CO";
	}
}