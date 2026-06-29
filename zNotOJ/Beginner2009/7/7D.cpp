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

int const N = 36;

int n;
string s[N];
vector<int> adj[N];

int res = N;
int col[N];

bool Check(string &a, string &b)
{
    if (sz(a) != sz(b)) return false;
    REP(i, sz(a)) if (a[i] != b[i] && a[i] != '*' && b[i] != '*') return true;
    return false;
}

void Solve()
{
    vector<int> v;
    FOR(i, 1, n) v.push_back(i), col[i] = MK(n) - 1;

    int ma = -1;

    while (!v.empty())
    {
        shuffle(all(v), mt19937_64(time(0)));

        int c = __builtin_ctz(col[v.back()] & -col[v.back()]);
        col[v.back()] = 0;

        for (auto &u : adj[v.back()]) if (col[u]) col[u] ^= MK(c);
        maxi(ma, c);

        v.clear();
        int mi = n;
        FOR(u, 1, n) if (col[u])
        {
            int cnt = __builtin_popcount(col[u]);
            if (mini(mi, cnt)) v = {u};
            else if (mi == cnt) v.push_back(u);
        }
    }

    mini(res, ma);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> s[i];

    FOR(i, 1, n) FOR(j, i + 1, n) if (Check(s[i], s[j]))
    {
        adj[i].push_back(j);
        adj[j].push_back(i);
    }

    REP(haha, 1e4) Solve();
    cout << res + 1;

    return 0;
}