#include <iostream>
#include <algorithm>
#include <time.h>

int n;
int m;

int result;

int main()
{
	//clock_t begin = clock();


	std::cin >> m >> n;

	/*for (int i = 1; i <= std::max(std::abs(m), std::abs(n)); i++)
	{
		if (n % i == 0 && m % i == 0)
		{
			result = i;
		}
	}*/

	m = std::abs(m);
	n = std::abs(n);

	if (m * n == 0)
	{
		result = m + n;
	}
	else
	{
		while (n != m)
		{
			if (m > n)
			{
				m -= n;
			}
			else
			{
				n -= m;
			}
		}

		result = m;
	}

	std::cout << result;



	/*clock_t end = clock(); 
	std::cout << "Time run: " << (float)(end - begin) / CLOCKS_PER_SEC << " s";*/
}