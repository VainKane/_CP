#include <bits/stdc++.h>

std::string Check(long long a, long long b);


int times;
long long a;
long long b;

std::string result[11];

int main()
{
    std::cin >> times;

    for (int i = 0; i < times; i++)
    {
        std::cin >> a >> b;
        result[i] = Check(a, b);
    }
    
    std::cout << result[0];

    for (int i = 1; i < times; i++)
    {
        std::cout << '\n' << result[i];
    }
    

}

std::string Check(long long a, long long b)
{
    std::string result = "YES";

    if (b - a != 1)
    {
        result = "NO";
    }
    else
    {
        for (int i = 2; i <= sqrt(a + b); i++)
        {
            if ((a + b) % i == 0)
            {
                result = "NO";
                break;
            }
        }
        
    }

    return result;
}