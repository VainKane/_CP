#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define BIT(i, x) (((x) >> (i)) & 1)
#define MK(i) (1ll << (i))
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

vector<int> v;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--)
    {
        int type, l, r;
        cin >> type;
        if (type == 1)
        {
            int x; cin >> x;
            v.push_back(x);
        }
        else if (type == 2)
        {
            cin >> l >> r;

            long long res = 0;
            for (auto &x : v) if (x >= l && x <= r) res += x;
            cout << res << '\n';
        }
        else
        {
            cin >> l >> r;
            l--; r--;
            
            long long res = 0;
            sort(all(v));

            FOR(i, l, r) res += v[i];
            v.push_back(v[l] + 1);
            v.push_back(v[r] - 1);

            cout << res << '\n';
        }
    }

    return 0;
}