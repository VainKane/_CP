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

int n, d;
vector<int> pos[N];

bool Check(int x)
{
    int avail = 1;
    REP(i, sz(pos[x]))
    {
        int cur = pos[x][i];
        if (avail > cur) return false;

        int id = upper_bound(all(pos[x]), cur + d - 1) - pos[x].begin() - 1;
        int l = max(avail, pos[x][id] - d + 1);
        avail = l + 2 * d;

        i = id;
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> d;
    FOR(i, 1, n)
    {
        int x; cin >> x;
        pos[x].push_back(i);
    }

    FOR(mex, 0, n) if (Check(mex))
    {
        cout << mex;
        return 0;
    }

    return 0;
}