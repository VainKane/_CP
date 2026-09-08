#include <bits/stdc++.h>

using namespace std;

int n;

bool Check(int x)
{
    if (x <= 1) return false;

    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0) return false;
    }

    return true;
}

int Rev(int x)
{
    int res = 0;

    while (x)
    {
        res *= 10;
        res += x % 10;
        x /= 10;
    }

    return res;
}

bool Solve(int x)
{
    return (Check(x) && Check(Rev(x)));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    cout << (Solve(n) ? "Yes" : "No");

    return 0;
}