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

int const N = 2e6 + 5;

int m, n, k;
vector<vector<int>> a, pre;

int t[N], b[N], l[N], r[N];
int x[N], y[N];

bool mark[N];

void Init()
{
    memset(l, 0x3f, sizeof l);
    memset(t, 0x3f, sizeof t);

    FOR(i, 1, m) FOR(j, 1, n)
    {
        int &id = a[i][j];
        mini(t[id], i); mini(l[id], j);
        maxi(b[id], i); maxi(r[id], j);
        x[id] = i, y[id] = j;
    }

    FOR(i, 1, k) pre[x[i]][y[i]] = 1;
    FOR(i, 1, m) FOR(j, 1, n) pre[i][j] += pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
}

int Get(int top, int bot, int left, int right)
{
    if (top > bot || left > right) return 0;
    return pre[bot][right] - pre[top - 1][right] - pre[bot][left - 1] + pre[top - 1][left - 1];
}

bool Outside(int x, int y, int id)
{
    if (x < t[id] || x > b[id]) return true;
    if (y < l[id] || y > r[id]) return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> m >> n >> k;
    a = pre = vector<vector<int>>(m + 5, vector<int>(n + 5, 0));
    FOR(i, 1, m) FOR(j, 1, n) cin >> a[i][j];

    Init();
    FOR(id, 1, k)
    {
        int res = Get(t[id], b[id], l[id], r[id]);
        
        FOR(i, t[id], b[id])
        {
            int idx = a[i][l[id]];
            if (Outside(x[idx], y[idx], id) && !mark[idx])
            {
                mark[idx] = true;
                res++;
            }

            idx = a[i][r[id]];
            if (Outside(x[idx], y[idx], id) && !mark[idx])
            {
                mark[idx] = true;
                res++;
            }
        }

        FOR(j, l[id], r[id])
        {
            int idx = a[t[id]][j];
            if (Outside(x[idx], y[idx], id) && !mark[idx])
            {
                mark[idx] = true;
                res++;
            }

            idx = a[b[id]][j];
            if (Outside(x[idx], y[idx], id) && !mark[idx])
            {
                mark[idx] = true;
                res++;
            }
        }

        FOR(i, t[id], b[id]) mark[a[i][l[id]]] = mark[a[i][r[id]]] = false;
        FOR(j, l[id], r[id]) mark[a[t[id]][j]] = mark[a[b[id]][j]] = false;

        cout << res - 1 << ' ';
    }

    return 0;
}