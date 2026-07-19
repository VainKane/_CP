#ifndef LOCALONLY
#include "molecules.h"
#endif // LOCALONLY

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

int const N = 2e5 + 5;
int const M = 5e5 + 5;

int l, r, n;
pair<int, int> a[N];

vector<int> find_subset(int ll, int uu, vector<int> ww)
{
    l = ll, r = uu, n = sz(ww);
    FOR(i, 1, n) a[i] = {ww[i - 1], i};

    sort(a + 1, a + n + 1);

    long long s = 0;
    int i = 0, j = 1;
    
    for (; i < n && s + a[i + 1].F <= r; s += a[++i].F);
    while (s < l && i < n) s += a[++i].F - a[j++].F;

    if (s < l || s > r) return {};

    vector<int> v;
    FOR(id, j, i) v.push_back(a[id].S - 1);
    return v;
}

#ifdef LOCALONLY
int main()
{
    int n, l, r;
    vector<int> w;

    cin >> n >> l >> r;
    w.assign(n, 0);
    REP(i, n) cin >> w[i];

    vector<int> res = find_subset(l, r, w);
    cout << sz(res) << '\n';
    for (auto &x : res) cout << x << ' ';

    return 0;
}
#endif // LOCALONLY