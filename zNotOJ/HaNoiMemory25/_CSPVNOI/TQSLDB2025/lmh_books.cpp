#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template<class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 1e6 + 5;

int n;
long long m;

int a[N], b[N];

long long suf[N];
int last[N];

bool used[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n) cin >> b[i];

    int idx = 0;
    FORD(i, n, 1)
    {
        if (last[a[i]]) maxi(idx, i + 1);
        else last[a[i]] = i;
        suf[i] = suf[i + 1] + b[i];
    } 

    int res = 0;
    long long s = 0;

    FOR(i, 0, n)
    {
        maxi(idx, last[a[i]] + 1);
        s += b[i];

        if (used[a[i]]) break;
        used[a[i]] = true;

        while (s + suf[idx] > m && idx <= n) idx++;
        if (s + suf[idx] <= m) maxi(res, i + n - idx + 1);
    }

    cout << res << '\n';

    return 0;
}