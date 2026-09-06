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
#define name ""

using ll = long long;
using ii = pair<int, int>;

template <class T> bool maxi(T &x, T const &y) { return x < y ? x = y, 1 : 0; }
template <class T> bool mini(T &x, T const &y) { return x > y ? x = y, 1 : 0; }

int const N = 2e5 + 5;
int const M = 309;

int n;
int x[N][2], y[N][2];
int xt, yt;

vector<int> adj[M][M];
bool visited[N];

char a[M][M];

void BFS()
{
    queue<int> q;
    FOR(i, 1, n) if (x[i][0] <= xt && xt <= x[i][1] && y[i][0] <= yt && yt <= y[i][1])
    {
        visited[i] = true;
        q.push(i);
    }

    while (!q.empty())
    {
        int i = q.front(); q.pop();
        REP(k, 2) for (auto &j : adj[x[i][k]][y[i][k]]) if (!visited[j])
        {
            visited[j] = true;
            q.push(j);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n)
    {
        REP(k, 2) cin >> x[i][k] >> y[i][k];
        if (x[i][0] > x[i][1]) swap(x[i][0], x[i][1]);
        if (y[i][0] > y[i][1]) swap(y[i][0], y[i][1]);
    }

    cin >> xt >> yt;

    FOR(i, 1, n) REP(k, 2) adj[x[i][k]][y[i][k]].push_back(i);
    BFS();

    int t, b, l, r;
    t = l = M, b = r = 0;
    
    FOR(i, 1, n) if (visited[i])
    {
        mini(l, x[i][0]), maxi(r, x[i][1]);
        mini(t, y[i][0]), maxi(b, y[i][1]);
    }

    memset(a, '.', sizeof a);
    FOR(i, 1, n) if (visited[i]) 
        FOR(u, y[i][0], y[i][1]) FOR(v, x[i][0], x[i][1]) a[b - u + 1][v] = '#';

    FOR(i, 1, b - t + 1)
    {
        FOR(j, l, r) cout << a[i][j];
        cout << '\n';
    }

    return 0;
}