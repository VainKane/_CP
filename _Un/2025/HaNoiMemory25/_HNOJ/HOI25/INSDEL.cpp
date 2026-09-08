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
#define name "INSDEL"

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const oo = 2e9 + 7;

vector<int> v[2];
int pre = 0, cur = 1;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    int idx = 1;

    v[cur] = {0};

    int q; cin >> q;
    FOR(i, 1, q)
    {
        int p, k;
        cin >> p >> k;

        swap(cur, pre);
        v[cur].clear();

        if (k > 0)
        {
            for (auto &x : v[pre]) if (x != p) v[cur].push_back(x);
            else
            {
                v[cur].push_back(x);
                FOR(i, idx, idx + k - 1) v[cur].push_back(i);
                idx += k;
            }
        }
        else
        {
            k = -k;
            int pos = -oo;
            REP(i, sz(v[pre]))
            {
                if (v[pre][i] == p) 
                {
                    pos = i;
                    v[cur].push_back(v[pre][i]);
                }
                else if (i > pos + k) v[cur].push_back(v[pre][i]);
            }
        }

        cout << v[cur][(sz(v[cur]) + 1) / 2 - 1] << '\n';

        // cout << "After op " << i << ":\n";
        // for (auto &x : v[cur]) cout << x << ' ';
        // cout << '\n';
    }

    return 0;
}