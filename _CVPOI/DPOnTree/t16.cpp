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
int const LOG = 17;

int n, q;
int up[N][20];

void Build()
{
    FOR(j, 1, 31 - __builtin_clz(n)) FOR(i, 1, n)
        up[i][j] = up[up[i][j - 1]][j - 1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    FOR(i, 2, n) cin >> up[i][0];

    Build();

    while (q--)
    {
        int u, k;
        cin >> u >> k;

        for (int tmp = k; tmp; tmp ^= tmp & -tmp)
        {
            int i = __builtin_ctz(tmp);
            u = up[u][i];
        }

        cout << (u ? u : -1) << '\n';
    }

    return 0;
}