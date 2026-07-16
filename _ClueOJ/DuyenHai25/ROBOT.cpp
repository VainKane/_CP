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

mt19937_64 rd(time(0));

long long Rand(long long l, long long r)
{
    return l + rd () * 1LL * rd() % (r - l + 1);
}

int const N = 209;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
char key[] = {'U', 'R', 'D', 'L'};

int m, n, k;
bool a[N][N];

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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    memset(a, true, sizeof a);

    cin >> m >> n >> k;
    FOR(i, 1, m) FOR(j, 1, n) cin >> a[i][j];
    
    int xs, ys;
    cin >> xs >> ys;
    xs++, ys++;

    REP(haha, 2.5e7)
    {
        int i = Rand(0, 3);

        int u = xs + dx[i];
        int v = ys + dy[i];

        cout << key[i];
        if (a[u][v]) continue;
        xs = u, ys = v;
    }

    BFS(xs, ys);
    cout << res[1][1];

    return 0;
}