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

int const N = 209;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
char key[] = {'U', 'R', 'D', 'L'};

int m, n, k;
bool a[N][N];
int xs[4], ys[4];

namespace Sub2
{
    bool CheckSub()
    {
        return k == 1;
    }

    string res[N][N];

    void BFS(int xs, int ys)
    {
        queue<pair<int, int>> q;
        q.push({xs, ys});

        a[xs][ys] = 1;

        while (!q.empty())
        {
            int x = q.front().F;
            int y = q.front().S;
            q.pop();

            REP(i, 4)
            {
                int u = x + dx[i];
                int v = y + dy[i];

                if (!a[u][v])
                {
                    a[u][v] = 1;
                    res[u][v] = res[x][y] + key[i];
                    q.push({u, v});
                }
            }
        }
    }

    void Process()
    {
        BFS(xs[1], ys[1]);
        cout << res[1][1];
    }
}

namespace Sub3
{
    bool CheckSub()
    {
        return k <= 3;
    }

    struct State
    {
        int x[4], y[4];
        
        State(int _x[], int _y[])
        {
            FOR(i, 1, 3) x[i] = _x[i], y[i] = _y[i];
        }
    };

    int const N = 12;
    bool visited[N][N][N][N][N][N];
    string res[N][N][N][N][N][N];

    bool Avail(int x[], int y[])
    {
        FOR(i, 1, 3) if (a[x[i]][y[i]]) return false;
        return true;
    }

    void BFS()
    {
        queue<State> q;
        q.push({xs, ys});
        visited[xs[1]][ys[1]][xs[2]][ys[2]][xs[3]][ys[3]] = true;

        while (!q.empty())
        {
            int x[4], y[4];
            int u[4], v[4];

            FOR(i, 1, 3) x[i] = q.front().x[i], y[i] = q.front().y[i];
            q.pop();

            REP(dir, 4)
            {
                FOR(i, 1, 3) 
                {
                    u[i] = x[i] + dx[dir];
                    v[i] = y[i] + dy[dir];
                    if (a[u[i]][v[i]]) u[i] = x[i], v[i] = y[i];
                }

                bool &vs = visited[u[1]][v[1]][u[2]][v[2]][u[3]][v[3]];
                if (Avail(u, v) && !vs)
                {
                    res[u[1]][v[1]][u[2]][v[2]][u[3]][v[3]] = 
                        res[x[1]][y[1]][x[2]][y[2]][x[3]][y[3]] + key[dir];
                    vs = true;
                    q.push({u, v});
                }
            }
        }
    }

    void Process()
    {
        if (k == 2) xs[3] = xs[1], ys[3] = ys[1];
        BFS();
        cout << res[1][1][1][1][1][1];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    memset(a, true, sizeof a);

    cin >> m >> n >> k;
    FOR(i, 1, m) FOR(j, 1, n) cin >> a[i][j];
    
    FOR(i, 1, k)
    {
        cin >> xs[i] >> ys[i];
        xs[i]++, ys[i]++;
    }

    if (Sub2::CheckSub()) return Sub2::Process(), 0;
    if (Sub3::CheckSub()) return Sub3::Process(), 0;

    return 0;
}