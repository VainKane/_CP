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

int const N = 509;

int n, m;
int c1[N][N], c2[N][N];
bool visited[N];

void DFS(int u)
{
    visited[u] = true;
    FOR(v, 1, n) if ((c1[u][v] || c2[u][v]) && !visited[v]) DFS(v); 
}

bool Check()
{
    memset(visited, false, sizeof visited);
    DFS(1);

    FOR(u, 1, n) if (!visited[u]) return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    FOR(i, 2, n)
    {
        int u, v;
        cin >> u >> v;
        c1[u][v] = c1[v][u] = 1;
    }

    FOR(i, 1, m)
    {
        int u, v;
        cin >> u >> v;
        c2[u][v]++; c2[v][u]++;
    }

    int res = 0;

    FOR(u, 1, n) FOR(v, u, n) if (c1[u][v])
    {
        c1[u][v]--; c1[v][u]--;
        
        FOR(i, 1, n) FOR(j, i, n) if (c2[i][j])
        {
            c2[i][j]--; c2[j][i]--;
            res += Check() * (c2[i][j] + 1);
            c2[i][j]++; c2[j][i]++;
        }

        c1[u][v]++; c1[v][u]++;
    }

    cout << res;

    return 0;
}