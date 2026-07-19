#include <bits/stdc++.h>

using namespace std;

int const N = 5005;

int n;
int m;

pair<int, int> v[N + 5];
double a[N][N];
bool used[N];
double d[N];

double GetLength(int x1, int y1, int x2, int y2)
{
    int a = x1 - x2;
    int b = y1 - y2;
    return sqrt(a * a + b * b);
}

void Prim()
{
    for (int i = 0; i <= n; i++) d[i] = 1e9;

    double res = 0;
    d[1] = 0;

    while (true)
    {
        int u = 0;
        for (int i = 1; i <= n; i++)
        {
            if (!used[i] && d[u] > d[i]) u = i;
        }

        if (u == 0) break;
        used[u] = 1;
        res += d[u];

        for (int i = 1; i <= n; i++)
        {
            if (!used[i] && d[i] > a[u][i]) 
            {
                d[i] = a[u][i];
            }
        }
    }
    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cout << fixed << setprecision(2);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        v[i] = {x, y};
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            a[i][j] = a[j][i] = GetLength(v[i].first, v[i].second, v[j].first, v[j].second);
        }
    }

    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;

        a[u][v] = 0;
        a[v][u] = 0;
    }

    Prim();

    return 0;
}