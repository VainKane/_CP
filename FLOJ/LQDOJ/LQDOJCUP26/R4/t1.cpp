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
#define name "qhtd"

using ll = long long;
using ii = pair<int, int>;

template <class T> bool maxi(T &x, T const &y) { return x < y ? x = y, 1 : 0; }
template <class T> bool mini(T &x, T const &y) { return x > y ? x = y, 1 : 0; }

int const N = 1009;
int const oo = 1e9 + 9;

int m, n;
char a[N][N];

int v[3][N][N];

bool mark[N][N];
int id[N][N];
int cc = 0;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

namespace Sub2
{
    bool CheckSub() { return m == 1; }

    int d[N];

    void Process()
    {
        FOR(i, 1, n) d[i] = v[2][1][i] - max(v[0][1][i], v[1][1][i]);

        ll res = 0;

        vector<ii> tr;
        FOR(i, 1 ,n) if (a[1][i] == '.') tr.push_back({1, i});

        FOR(l, 1, n) if (a[1][l] == '.')
        {
            ii mn = {oo, 0};
            int r = l;
            for (; r <= n && a[1][r] != '#'; r++) mini(mn, {d[r], r});
            l = r;

            FOR(i, l, mn.S - 1)
            {
                if (v[0][1][i] > max(v[1][1][i], v[2][1][i])) tr.push_back({3, i});
                else if (v[2][1][i] > tr..push_back({})
            }
        }
    }
}

namespace Sub3
{
    bool CheckSub()
    {
        FOR(i, 1, m) FOR(j, 1, n) if (v[2][i][j] > v[1][i][j]) return false;
        return true;
    }

    void Process()
    {
        ll res = 0;
        vector<ii> tr;

        FOR(i, 1, m) FOR(j, 1, n)
        {
            res += max(v[0][i][j], v[1][i][j]);
            if (v[1][i][j] > v[0][i][j]) tr.push_back({i, j});
        }

        cout << res << '\n' << sz(tr) << '\n';
        for (auto &p : tr) cout << "1 "<< p.F << ' ' << p.S << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> m >> n;
    FOR(i, 1, m)
    {
        string s; cin >> s;
        FOR(j, 1, n) a[i][j] = s[j - 1];
    }

    REP(k, 3) FOR(i, 1, m) FOR(j, 1, n) cin >> v[k][i][j];

    if (Sub3::CheckSub()) return Sub3::Process(), 0;

    return 0;
}