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

int const N = 50;

int n;
string s[N];

int id[N];

bool c[N][N];
int deg[N];

int res;

bool Equal(string a, string b)
{
    if (sz(a) != sz(b)) return false;
    REP(i, sz(a))
    {
        if (a[i] == '*' || b[i] == '*') continue;
        if (a[i] != b[i]) return false;
    }
    return true;
}

bool cmp(int id1, int id2)
{
    return deg[id1] > deg[id2];
}

bool Check(vector<int> &clique, int i)
{
    for (auto &j : clique) if (!c[i][j]) return false;
    return true;
}

void Try(vector<vector<int>> &cliques, int pos)
{
    if (pos > n)
    {
        mini(res, sz(cliques));
        return;
    }

    bool inserted = false;
    REP(i, sz(cliques)) if (Check(cliques[i], id[pos]))
    {
        cliques[i].push_back(id[pos]);
        Try(cliques, pos + 1);
        cliques[i].pop_back();

        inserted = true;
    }

    if (!inserted)
    {
        cliques.push_back(vector<int> {id[pos]});
        Try(cliques, pos + 1);
        cliques.pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> s[i], id[i] = i;

    FOR(i, 1, n) FOR(j, 1, n) if (i != j && Equal(s[i], s[j]))
    {
        c[i][j] = true;
        deg[i]++;
    }

    sort(id + 1, id + n + 1, cmp);

    vector<vector<int>> cliques;
    res = n;

    Try(cliques, 1);
    cout << res;

    return 0;
}