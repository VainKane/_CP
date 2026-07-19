#include <bits/stdc++.h>

void Check(int n, std::string& resultOut);

int times;
int n;
std::string result;

int main()
{
	/*freopen("step.inp", "r", stdin);
	freopen("step.out", "w", stdout);*/

	std::cin >> times;

	for (int i = 0; i < times; i++)
	{
		std::cin >> n;
		Check(n, result);
	}

	result.erase(result.length() - 1);
	std::cout << result;

}

void Check(int n, std::string &resultOut)
{
	std::string result;

	if (n / 10 > 0)
	{
		result = "YES";
	}
	else
	{
		result = "NO";
	}
	int preNum;

	while (n > 0)
	{
		preNum = n % 10;

		n /= 10;


		if (n % 10 > preNum)
		{
			result = "NO";
			break;
		}

	}

	resultOut += result + '\n';
}