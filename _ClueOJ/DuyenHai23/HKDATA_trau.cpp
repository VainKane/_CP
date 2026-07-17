#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define BIT(i, x) (((x) >> (i)) & 1)
#define MK(i) (1LL << (i))
#define all(v) v.begin(), v.end()
#define sz(v) ((int)v.size())
#define F first
#define S second

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}


int const N = 1e5 + 5;
long long const oo = 1e18;

int n, q;

int a[N];
long long pre[N];

long long preMax[N], preMin[N];
long long sufMax[N], sufMin[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;

    sufMax[0] = sufMax[n + 1] = -oo;
    sufMin[0] = sufMin[n + 1] = oo;

    FOR(i, 1, n) 
    {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    
        preMax[i] = max(pre[i], preMax[i - 1]);
        preMin[i] = min(pre[i], preMin[i - 1]);
    }

    FORD(i, n, 1)
    {
        sufMax[i] = max(sufMax[i + 1], pre[i]);
        sufMin[i] = min(sufMin[i + 1], pre[i]);
    }

    while (q--)
    {
        int l, r, c;
        cin >> l >> r >> c;
        
        long long x = 1LL * (r - l + 1) * c;
        long long ma = max(preMax[l - 1], sufMax[r + 1] + x);
        long long mi = min(preMin[l - 1], sufMin[r + 1] + x);

        FOR(i, l, r)
        {
            maxi(ma, pre[i] + 1LL * (i - l + 1) * c);
            mini(mi, pre[i] + 1LL * (i - l + 1) * c);
        }

        cout << ma - mi << '\n';
    }

    return 0;
}