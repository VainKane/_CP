#include <bits/stdc++.h>

std::string Solve(int n, int a, int b, int &xOut, int &yOut);


int n;

int a;
int b;

int x = 0; 
int y = 0;

int main()
{
    freopen("Buy.inp", "r", stdin);
    freopen("Buy.out", "w", stdout);

    std::cin >> n >> a >> b;

    std::cout << Solve(n, a, b, x, y) << '\n';
    
    if (x + y != 0)
    {
        std::cout << x << ' ' << y;
    }
}

std::string Solve(int n, int a, int b, int &xOut, int &yOut)
{
    for (int y = 1; y <= n / b; y++)
    {
        if ((n - y * b) % a == 0 && (n - x * a) % b == 0)
        {
            if (n - x * a > 0)
            {
                yOut = y;
                xOut = (n - y * b) / a;
                return "YES";
            }
            else
            {
                return "NO";
            }
        } 
        else
        {
            return "NO";
        }
    }
    return "NO";
}