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

int const N = 3009;

int n;

pair<int, int> a[N];
int pos[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n)
    {
        int x; cin >> x;
        a[i] = {x, i};
        pos[i] = i;
    }

    vector<pair<int, int>> res;

    FOR(i, 1, n)
    {
        int idx = i;
        FOR(j, i + 1, n) if (a[j] < a[idx]) idx = j;

        res.push_back({i - 1, idx - 1});
        swap(a[i], a[idx]);
    }

    cout << sz(res) << '\n';
    for (auto &p : res) cout << p.F << ' ' << p.S << '\n';

    return 0;
}