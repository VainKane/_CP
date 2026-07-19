#include <bits/stdc++.h>

long long n;
std::string result;

int main()
{
	std::cin >> n;
	
	result = "YES";

	if (n <= 0)
	{
		result = "NO";
	}

	while (n > 0)
	{
		if (n % 10 != 8 && n % 10 != 6)
        {
            result = "NO";
            break;
        } 

		n /= 10;
	}

	

	std::cout << result;
}