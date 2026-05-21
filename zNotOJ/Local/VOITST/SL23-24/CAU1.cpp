#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define name "CAU1"

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

int const N = 1e7 + 5;

int n;
int cnt[N], cntDiv[N];

int gcd;

int GCD(int a, int b)
{
    while (true)
    {
        if (a == 0 || b == 0 || a == b) return a | b;
        if (a > b) a %= b; else b %= a;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    int ma = 0;

    cin >> n;
    FOR(i, 1, n)
    {
        int x; cin >> x;
        
        cnt[x]++;
        gcd = (i == 1) ? x : GCD(gcd, x);

        ma = max(ma, x);
    }

    int res = 0;

    FOR(i, gcd + 1, ma) 
    {
        for (int j = i; j <= ma; j += i) cntDiv[i] += cnt[j];
        maxi(res, cntDiv[i]);
    }

    res = n - res;
    if (res == n) res = -1;
    
    cout << res;

    return 0;
}