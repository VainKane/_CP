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
#define name ""

using ll = long long;
using ii = pair<int, int>;

template <class T> bool maxi(T &x, T const &y) { return x < y ? x = y, 1 : 0; }
template <class T> bool mini(T &x, T const &y) { return x > y ? x = y, 1 : 0; }

int const N = 109;
int const oo = 1e9 + 9;

int n;

int c[N][N];
ll d[N][N][N];

void Floyd()
{
    memset(d, 0x3f, sizeof d);

    FOR(u, 1, n) d[u][u][1] = 0;
    FOR(u, 1, n) FOR(v, 1, n) if (c[u][v]) d[u][v][1] = c[u][v];

    FOR(k, 1, n) FOR(u, 1, n) FOR(v, 1, n) if (k != u && k != v)
        mini(d[u][v][1], d[u][k][1] + d[k][v][1]);

    FOR(x, 2, n - 1) FOR(u, 1, n) FOR(v, 1, n)
    {
        d[u][v][x] = d[u][v][x - 1];
        FOR(k, 1, n) if (k != u && k != v) mini(d[u][v][x], max(d[u][k][x - 1], d[k][v][1]));
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) FOR(j, 1, n) cin >> c[i][j];

    Floyd();

    int q; cin >> q;
    while (q--)
    {
        int u, v, t;
        cin >> u >> v >> t;
        cout << (d[u][v][t] < 1e18 ? d[u][v][t] : 0) << '\n';
    }

    return 0;
}