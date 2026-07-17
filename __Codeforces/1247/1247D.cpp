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
map<vector<pair<int, int>>, int> mp;

vector<pair<int, int>> GetFactor(int x)
{
    map<int, int> mp;

    FOR(i, 2, sqrt(x))
    {
        while (x % i == 0)
        {
            int &tmp = mp[i];
            if (++tmp == k) tmp = 0;
            x /= i;
        }
    }

    if (x != 1)
    {
        int &tmp = mp[x];
        if (++tmp == k) tmp = 0;
    }

    vector<pair<int, int>> res;
    for (auto &p : mp) if (p.S) res.push_back(p);
    return res;
}

vector<pair<int, int>> GetOp(vector<pair<int, int>> &ft)
{
    vector<pair<int, int>> res;
    for (auto &p : ft) res.push_back({p.F, k - p.S});
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;

    long long res = 0;

    FOR(i, 1, n)
    {
        int x; cin >> x;
        auto ft = GetFactor(x);

        res += mp[GetOp(ft)];
        mp[ft]++;
    }

    cout << res;

    return 0;
}