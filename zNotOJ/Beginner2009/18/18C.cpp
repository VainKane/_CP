#include <bits/stdc++.h>

using namespace std;

int const N = 109;

int n;
int m;

char a[N][N];
pair<int, int> trace[N][N];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

pair<int, int> start;

void Print(int u, int v)
{
    vector<pair<int, int>> res;
    
    while (make_pair(u, v) != start)
    {
        res.push_back({u, v});
        pair<int, int> p = trace[u][v];
        u = p.first;
        v = p.second;
    }

    res.push_back(start);
    cout << "YES\n";
    for (int i = res.size() - 1; i >= 0; i--)
    {
        cout << res[i].first << ' ' << res[i].second << '\n';
    }

    exit(0);
}

void DFS(int u, int v)
{
    for (int i = 0; i < 4; i++)
    {
        int p = u + dx[i];
        int q = v + dy[i];

        if (p * q == 0 || p == m + 1 || q == n + 1)
        {
            Print(u, v);
        }
        if (a[p][q] != '.') continue;
        if (!trace[p][q].first && !trace[p][q].second)
        {
            trace[p][q] = {u, v};
            DFS(p, q);
        }
    }
}

void BFS(int u, int v)
{
    queue<pair<int, int>> qu;
    qu.push({u, v});

    while (!qu.empty())
    {
        int u = qu.front().first;
        int v = qu.front().second;
        qu.pop();

        for (int i = 0; i < 4; i++)
        {
            int p = u + dx[i];
            int q = v + dy[i];

            if (p * q == 0 || p == m + 1 || q == n + 1)
            {
                Print(u, v);
            }
            if (a[p][q] != '.') continue;
            if (!trace[p][q].first && !trace[p][q].second)
            {
                trace[p][q] = {u, v};
                qu.push({p, q});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> m >> n;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 'E') start = {i, j};
        }
    }

    BFS(start.first, start.second);
    cout << "NO";

    return 0;
}