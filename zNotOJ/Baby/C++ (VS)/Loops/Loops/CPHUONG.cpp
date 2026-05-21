#include <iostream>
#include <cmath>
#include <string>

int n;
int count;
std::string result;

int main()
{
	std::cin >> n;

	for (int i = 1; i <= n; i++)
	{
		if (static_cast<int>(std::sqrt(i)) * static_cast<int>(std::sqrt(i)) == i)
		{
			count += 1;
			result += std::to_string(i) + " ";
		}
	
	}

	result.erase(result.length() - 1);

	std::cout << count << '\n';
	std::cout << result;
}