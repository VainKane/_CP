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

int n, k;
long long pre[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    
    FOR(i, 1, n)
    {
        cin >> pre[i];
        pre[i] = pre[i] == 1 ? 1 : -1;
    }
    
    FOR(i, 1, n)
    {
        int x; cin >> x;
        pre[i] *= x;

        pre[i] += pre[i - 1];
    }

    int q; cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;

        long long res = 0;
        FOR(i, l, r) FOR(j, l, i) res += pre[i] - pre[j - 1] == k;
        cout << res << '\n';
    }

    return 0;
}