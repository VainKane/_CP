#include <bits/stdc++.h>

int n;
int count;

int result[1000];

int main()
{
	std::cin >> n;

	for (int i = 1; i <= n; i++)
	{
		if ((int)sqrt(i) * (int)sqrt(i) == i)
		{
            result[count] = i;
			count += 1;
		}
	
	}

    std::cout << count << '\n' << result[0];
    
    for (int i = 1; i < count; i++)
    {
        std::cout << ' ' << result[i];
    }
}