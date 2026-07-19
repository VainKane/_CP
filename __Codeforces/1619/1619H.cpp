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
int const BK = 314;

int n, q;
int p[N];

int pos[N], id[N];

void Update(int idx)
{
    pos[idx] = idx;
    FOR(haha, 1, BK) pos[idx] = p[pos[idx]];

    int ed = id[pos[idx]];
    idx = id[idx];

    FOR(haha, 1, BK)
    {
        id[p[idx]] = idx;
        pos[idx] = ed;
        ed = id[ed];
        idx = id[idx];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    FOR(i, 1, n) cin >> p[i];

    FOR(i, 1, n)
    {
        pos[i] = i;
        id[p[i]] = i;
        FOR(haha, 1, BK) pos[i] = p[pos[i]];
    }

    while (q--)
    {
        int type, x, y;
        cin >> type >> x >> y;

        if (type == 1)
        {
            swap(p[x], p[y]);
            id[p[x]] = x, id[p[y]] = y;
            Update(x), Update(y);
        }
        else
        {
            while (y >= BK) x = pos[x], y -= BK;
            while (y--) x = p[x];
            cout << x << '\n';
        }
    }

    return 0;
}