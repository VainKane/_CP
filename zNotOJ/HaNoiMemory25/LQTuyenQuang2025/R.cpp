#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

int const N = 3e5 + 5;
int const oo = 1e9 + 1;

int n, k;
int a[N];

long long s[N];
int pre[N], suf[N];

long long Get(int l, int r)
{
    if (l > r) return oo;
    return s[r] - s[l - 1];
}

long long Solve()
{
    pre[0] = suf[n + 1] = oo;
    long long res = 0;

    FOR(i, 1, n) 
    {
        s[i] = s[i - 1] + a[i];
        pre[i] = min(pre[i - 1], a[i]);
    }

    FORD(i, n, 1) suf[i] = min(suf[i + 1], a[i]);

    FOR(l, 1, n)
    {   
        int r = min(n, l + n - k);
        int mi = k == 2 ? min(Get(1, l - 1), Get(r + 1, n)) : min(pre[l - 1], suf[r + 1]);
        maxi(res, Get(l, r) - mi);
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    FOR(i, 1, n) cin >> a[i];

    long long res = Solve();
    reverse(a + 1, a + n + 1);
    maxi(res, Solve());

    cout << res;

    return 0;
}