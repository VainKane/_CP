#include <bits/stdc++.h>

using namespace std;

int n;

int Count(int x)
{
    int cnt = 0;
    while (x)
    {
        cnt++;
        x /= 10;
    }
    return cnt;
}

int Solve()
{
    int s = 0;
    for (int i = 4; i <= 1e4; i++)
    {
        s += Count(i);
        if (s == n) return i;
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    cout << Solve();

    return 0;
}