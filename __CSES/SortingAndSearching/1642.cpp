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

int const N = 1009;

int n, x;
int a[N];
map<int, pair<int, int>> mp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> x;
    FOR(i, 1, n) cin >> a[i];

    FOR(i, 1, n) FOR(j, i + 1, n) if (a[i] + a[j] < x) mp[a[i] + a[j]] = {i, j};
    FOR(i, 1, n) FOR(j, i + 1, n) if (a[i] + a[j] < x)
    {
        auto it = mp.find(x - a[i] - a[j]);
        if (it != mp.end() && it->S.F > j)
        {
            cout << i << ' ' << j << ' ' << it->S.F << ' ' << it->S.S;
            return 0;
        }
    }
    
    cout << "IMPOSSIBLE";

    return 0;
}