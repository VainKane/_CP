#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define all(v) v.begin(), v.end()
#define sz(v) ((int)v.size())
#define MK(i) (1ll << (i))
#define F first
#define S second

struct Rect
{
    int x1, y1, x2, y2;
};

int const N = 55;

int m, n, k;
Rect a[N];

vector<int> xVals, yVals;

long long mask[2 * N][2 * N];
bool visited[2 * N][2 * N];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

bool isInside(int x, int y)
{
    return  x >= 2 && x <= sz(xVals) && 
            y >= 2 && y <= sz(yVals);
}

void BFS(int xs, int ys)
{
    queue<pair<int, int>> q;
    q.push({xs, ys});

    visited[xs][ys] = true;

    while (!q.empty())
    {
        int x = q.front().F;
        int y = q.front().S;
        q.pop();

        REP(i, 4)
        {
            int u = x + dx[i];
            int v = y + dy[i];

            if (!isInside(u, v) || visited[u][v]) continue;
            if (mask[u][v] != mask[x][y]) continue;

            visited[u][v] = true;
            q.push({u, v});
        }
    }
}

int GetId(vector<int> &vals, int const &x)
{
    return lower_bound(all(vals), x) - vals.begin() + 1;
}

void Reset()
{
    xVals.clear(); yVals.clear();
    memset(mask, 0, sizeof mask);
    memset(visited, false, sizeof visited);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    
    while (cin >> m >> n)
    {
        if (m == 0 && n == 0) return 0;
        Reset();
        
        cin >> k;
        FOR(i, 1, k)
        {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            
            if (x1 > x2) swap(x1, x2);
            if (y1 > y2) swap(y1, y2);

            a[i] = {x1, y1, x2, y2};
            xVals.push_back(x1); xVals.push_back(x2);
            yVals.push_back(y1); yVals.push_back(y2);
        }

        xVals.push_back(0); yVals.push_back(0);
        xVals.push_back(n); yVals.push_back(m);

        sort(all(xVals)); sort(all(yVals));
        xVals.erase(unique(all(xVals)), xVals.end());
        yVals.erase(unique(all(yVals)), yVals.end());

        FOR(i, 1, k)
        {
            FOR(x, GetId(xVals, a[i].x1) + 1, GetId(xVals, a[i].x2))
            {
                FOR(y, GetId(yVals, a[i].y1) + 1, GetId(yVals, a[i].y2))
                {
                    mask[x][y] |= MK(i - 1);
                }
            }
        }

        int res = 0;
        FOR(i, 2, sz(xVals)) FOR(j, 2, sz(yVals)) if (!visited[i][j]) 
        {
            BFS(i, j);
            res++;
        }

        cout << res << '\n';
    }
    
    return 0;
}