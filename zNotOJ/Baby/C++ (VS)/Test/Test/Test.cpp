#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <stdio.h>
#include <cmath>
#include <iomanip>

bool Solve(int n, int a, int b, int& xOut, int& yOut);


int a = 3;
int b = 4;
int c;
int i = 999;

std::string abc;

int intt[5];


int main()
{
	/*while (true)
	{
		char test;
		std::cin >> test;
		std::cout << (int)test << std::endl << "---\n";
	}*/
	

	/*for (int i = 0; i < 6; i++)
	{
		std::cout << "lan lap thu " << i << '\n';
		std::cout << "day la phan dau cua vong lap\n";

		if (i > 2) continue;
		
		std::cout << "day la phan con lai cua vong lap\n";
	}*/


	/*while (true)
	{
		std::cout << "Day la phan dau vong lap thu nhat\n";

		while (true)
		{
			std::cout << "Day la vong lap thu 2\n";
		}
		break;
		std::cout << "Day la phan cuoi vong lap thu nhat\n";
	}*/

	/*int arr[4];

	for (int i = 0; i <= 4; i++)
	{
		std::cout << "Phan tu thu " << i + 1 << '\n';
	}*/
	
	//std::cout << (char)5;


	/*for (long long i = 0; i <= sqrt(2 * std::pow(10, 4)); i++)
	{
		if (n % i == 0)
		{
			std::cout << "nah";
			break;
		}
	} */
	
	if (2.00 == 1.00)
	{
		std::cout << "sdf";
	}
}



bool Solve(int n, int a, int b, int& xOut, int& yOut)
{
	for (int y = 0; y <= n; y++)
	{
		if ((n - y * b) % a == 0)
		{
			yOut = y;
			xOut = (n - y * b) / a;

			return true;
		}
	}

	return false;
}