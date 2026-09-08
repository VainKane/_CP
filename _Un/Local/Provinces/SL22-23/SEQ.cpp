#include <bits/stdc++.h>

using namespace std;

int const N = 2e5 + 5;

int n;
int a[N];

long long p[N];
long long r[N];

long long GetSum(int l, int r)
{
    return p[r] - p[l - 1];
}

void Init()
{
    for (int i = 1; i <= n; i++) p[i] = p[i - 1] + a[i];
    memset(r, -0x3f, sizeof r);

    for (int i = 1; i <= n; i++)
    {
        for (int j = i - 2; j >= 1; j -= 3)
        {
            r[i] = max(r[i], GetSum(j, i));
        }
        r[i] = max(r[i], r[i - 1]);
    }
}

void Solve()
{
    long long res = -1e18;

    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 2; j <= n; j += 3)
        {
            res = max(res, GetSum(i, j) + r[i - 1]);
        }
    }
    
    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    Init();
    Solve();

    return 0;
}