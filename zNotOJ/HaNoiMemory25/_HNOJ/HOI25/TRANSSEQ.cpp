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
#define name "TRANSSEQ"

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int k, q;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> k >> q;
    while (q--)
    {
        int s, n, l, r, v;
        cin >> s >> n >> l >> r >> v;
        l--; r--;

        vector<int> ve = {s};
        FOR(i, 1, n)
        {
            vector<int> tmp;
            for (auto &x : ve)
            {
                if (x < k) tmp.push_back(x + 1);
                else FORD(d, k, 0) tmp.push_back(d);
            }

            ve = tmp;
        }

        int res = 0;
        FOR(i, l, r) res += ve[i] == v;
        cout << res << '\n';
    }

    return 0;
}