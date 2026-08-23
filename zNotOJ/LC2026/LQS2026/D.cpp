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

int const N = 3006;

struct Segment
{
    int l, r, x;
    Segment(int _l = 0, int _r = 0, int _x = 0) { l = _l, r = _r, x = _x; }
    bool operator < (Segment const other) const { return r < other.r; }
};

int m, n, h, w;
char a[N][N];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int id[N][N];
int cc = 0;

vector<ii> pos[N * N];
int pre[N][N];

void BFS(int xs, int ys)
{
    vector<ii> q = {{xs, ys}};
    id[xs][ys] = ++cc;

    while (!q.empty())
    {
        int x = q.back().F, y = q.back().S;
        q.pop_back();

        pos[cc].push_back({x, y});

        REP(i, 4)
        {
            int u = x + dx[i], v = y + dy[i];
            if (a[u][v] == 'x' && !id[u][v])
            {
                id[u][v] = cc;
                q.push_back({u, v});
            }
        }
    }
}

void Update(int top, int bot, int left, int right, int delta)
{
    pre[top][left] += delta, pre[bot + 1][right + 1] += delta;
    pre[top][right + 1] -= delta, pre[bot + 1][left] -= delta;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> m >> n >> h >> w;
    FOR(i, 1, m) FOR(j, 1, n) cin >> a[i][j];

    FOR(i, 1, m) FOR(j, 1, n) if (a[i][j] == 'x' && !id[i][j]) BFS(i, j);

    FOR(id, 1, cc)
    {
        sort(all(pos[id]));
        set<Segment> s;
        
        for (auto &p : pos[id])
        {
            Segment cur = {max(1, p.S - w + 1), p.S, p.F};
            Update(max(1, cur.x - h + 1), cur.x, cur.l, cur.r, 1);

            vector<Segment> sg = {cur};
            auto it = s.lower_bound({0, cur.r - w + 1, 0});

            while (it != s.end() && it->l <= cur.r)
            {
                if (it->l < cur.l) sg.push_back({it->l, cur.l - 1, it->x});
                if (it->r > cur.r) sg.push_back({cur.r + 1, it->r, it->x});

                if (it->x >= cur.x - h + 1)
                {
                    int l = max(cur.l, it->l);
                    int r = min(cur.r, it->r);
                    Update(max(1, cur.x - h + 1), it->x, l, r, -1);
                }

                s.erase(it);
                it = s.lower_bound({0, cur.r - w + 1, 0});
            }

            for (auto &seg : sg) s.insert(seg);
        }
    }

    int res = 0;
    FOR(i, 1, m) FOR(j, 1, n) maxi(res, pre[i][j] += pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1]);
    cout << res;

    return 0;
}