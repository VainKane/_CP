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

int const N = 36;

int n;

vector<int> adj[N];
bool go[N][N];

vector<vector<int>> cls;
vector<int> divs;
int res;

int clId[N];

bool Check(int i, vector<int> &clique)
{
    for (auto &j : clique) if (!go[i][j]) return false;
    return true;
}

void Try(int pos, vector<vector<int>> cliques)
{
    if (pos == sz(divs))
    {
        if (mini(res, sz(cliques))) cls = cliques;
        return;
    }

    for (auto &i : adj[pos]) if (clId[i] != -1)
    {
        assert(clId[i] >= 0 && clId[i] < sz(cliques));
        auto &cl = cliques[clId[i]];
        if (!Check(pos, cl)) continue;

        cl.push_back(pos);
        clId[pos] = clId[i];
        Try(pos + 1, cliques);
        cl.pop_back();

        clId[pos] = -1;
    }

    cliques.push_back({{pos}});
    clId[pos] = sz(cliques) - 1;

    Try(pos + 1, cliques);

    cliques.pop_back();
    clId[pos] = -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--)
    {
        cin >> n;

        divs.clear();
        FOR(i, 1, n) if (n % i == 0) divs.push_back(i);

        memset(go, false, sizeof go);
        REP(i, sz(divs)) adj[i].clear();

        REP(i, sz(divs)) FOR(j, i + 1, sz(divs) - 1) if (divs[j] % divs[i] == 0)
        {
            go[i][j] = go[j][i] = true;
            adj[i].push_back(j);
            adj[j].push_back(i);
        }

        memset(clId, -1, sizeof clId);
        res = N;
        Try(0, vector<vector<int>> {});

        cout << res << '\n';
        for (auto &cl : cls)
        {
            cout << sz(cl) << ' ';
            for (auto &i : cl) cout << divs[i] << ' ';
            cout << '\n';
        }
    }

    return 0;
}