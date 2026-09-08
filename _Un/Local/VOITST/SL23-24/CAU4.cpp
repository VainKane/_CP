#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define name "CAU4"

long long n, m, k;

long long Smaller(long long x)
{
    long long res = 0;
    FOR(i, 1, n) 
        res += min(m, x % i == 0 ? x / i - 1 : x / i);

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> m >> k;
    
    long long l = 1;
    long long r = n * m;
    long long res = l;

    while (l <= r)
    {
        long long mid = (l + r) / 2;
        if (Smaller(mid) < k)
        {
            res = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }

    cout << res;

    return 0;
}