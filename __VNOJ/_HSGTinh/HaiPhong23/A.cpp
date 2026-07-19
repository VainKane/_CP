#include <bits/stdc++.h>

using namespace std;

int n;

int Solve(int x)
{
    int res = 0;
    for (int i = 1; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            res++;
            res += (i * i != x);
        }
    }

    return res;
}

int main()
{
    cin >> n;   
    cout << Solve(n);
}