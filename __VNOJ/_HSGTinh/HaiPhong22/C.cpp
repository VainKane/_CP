#include <bits/stdc++.h>

using namespace std;

#define name "C"

int const N = 25;

int n;
long long x;

int p[N];
int t[N];

long long Cal(long long x)
{
    long long res = 0;
    for (int i = 1; i <= n; i++)
    {
        res += (x - p[i]) / t[i] + 1;
    }
    return res;
}

void Solve()
{
    long long l = 1;
    long long r = 1e18;
    long long res;

    while (l <= r)
    {
        long long mid = l + (r - l) / 2;
        if (Cal(mid) >= x)
        {
            res = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    
    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen(name".inp", "r", stdin);
    // freopen(name".out", "w", stdout);

    cin >> n >> x;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i] >> t[i];
    }

    Solve();

    return 0;
}