#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

bool Check(int x)
{
    FOR(i, 2, sqrt(x)) if (x % i == 0) return false;
    return x > 1;
}

int Sum(int x)
{
    int res = 0;
    while (x)
    {
        res += (x % 10) * (x % 10);
        x /= 10;
    }
    return res;
}

int Solve(int n)
{
    int cnt = 0;
    int res = 10;

    while (cnt < n) cnt += Check(Sum(++res));
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    while (cin >> n) cout << Solve(n) << '\n';

    return 0;
}