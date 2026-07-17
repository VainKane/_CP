#include <bits/stdc++.h>

int TimeCal(int n, int x);


int times;
int n;
int x;

int main()
{
    freopen("Schedule.inp", "r", stdin);
    freopen("Schedule.out", "w", stdout);

    std::cin >> times;

    for (int i = 0; i < times; i++)
    {
        std::cin >> n >> x;
        std::cout << TimeCal(n, x) << '\n';
    }
}

int TimeCal(int n, int x)
{
    int t1 = 10 * (n - 1);
    int t2 = x * (n - 1);

    if (t1 > t2)
    {
        return t1 - t2;
    }
    else
    {
        return 0;
    }
}
