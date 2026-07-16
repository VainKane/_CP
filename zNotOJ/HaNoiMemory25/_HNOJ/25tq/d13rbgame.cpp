#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define all(v) v.begin(), v.end()

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

struct Data
{
    long long dxy;
    int x, y;

    bool operator < (Data const other) const
    {
        return dxy > other.dxy;
    }
};

long long const oo = 1e18;

int m, n;
vector<vector<long long>> a;
vector<vector<long long>> d;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

long long GetVal(char ch)
{
    if (ch == '#') return 0;
    if (ch == '.') return oo;
    return ch - '0';
}

bool Inside(int x, int y)
{
    return  x >= 1 && x <= m &&
            y >= 1 && y <= n;
}

void Dijkstra()
{
    priority_queue<Data> pq;

    FOR(j, 1, n) if (a[m][j] != oo)
    {
        d[m][j] = a[m][j];
        pq.push({d[m][j], m, j});
    }

    FOR(i, 1, m) if (a[i][1] != oo)
    {
        d[i][1] = a[i][1];
        pq.push({d[i][1], i, 1});
    }

    while (!pq.empty())
    {
        int x = pq.top().x;
        int y = pq.top().y;
        long long dxy = pq.top().dxy;
        pq.pop();

        if (dxy > d[x][y]) continue;

        REP(i, 4)
        {
            int u = x + dx[i];
            int v = y + dy[i];

            if (!Inside(u, v) || a[u][v] == oo) continue;
            if (mini(d[u][v], d[x][y] + a[u][v])) pq.push({d[u][v], u, v});
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> m >> n;
    a.assign(m + 5, vector<long long> (n + 5, 0));
    d.assign(m + 5, vector<long long> (n + 5, 4 * oo));

    FOR(i, 1, m) FOR(j, 1, n)
    {
        char ch; cin >> ch;
        a[i][j] = GetVal(ch);
    }

    Dijkstra();

    long long res = a[m - 1][m] + a[m][n - 1];
    
    FOR(i, 1, m) mini(res, d[i][n]);
    FOR(j, 1, n) mini(res, d[1][j]);
    
    if (res >= oo) res = -1;
    cout << res;

    return 0;
}