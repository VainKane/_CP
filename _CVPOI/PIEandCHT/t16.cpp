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
int const Q = 3e5 + 5;
long long const oo = 1e18;

struct Segment
{
    long long x, a, b;
    int id;

    long long Val()
    {
        return x * a + b;
    }
};

struct ConvexHullTrick
{

};

int n, q;
int v[N], t[N], id[N];

pair<int, int> qr[Q];
long long res[Q];

bool cmp(int i, int j)
{
    return t[i] < t[j];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    FOR(i, 1, n) cin >> t[id[i] = i] >> v[i], v[i] = abs(v[i]);
    FOR(i, 1, q) cin >> qr[i].F, qr[i].S = i;

    sort(id + 1, id + n + 1, cmp);
    sort(qr + 1, qr + q + 1);

    FOR(i, 1, q)
    {
        int ti = qr[i].F;

        long long mi = oo;
        FOR(j, 1, n) if (t[j] <= ti) if (mini(mi, 1LL * (ti - t[j]) * v[j])) res[qr[i].S] = j;
        if (mi == oo) res[qr[i].S] = -1;
    }

    FOR(i, 1, q) cout << res[i] << ' ';

    return 0;
}