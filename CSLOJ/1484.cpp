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
#define left __left
#define right __right

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 1009;

int m, n;

int a[N][N];
int pre[N][N];

pair<int, int> root[N * N];
bool used[N * N];

vector<int> colors;
int top, bot, left, right;

int GetSum()
{
    return pre[bot][right] - pre[bot][left - 1] - pre[top - 1][right] + pre[top - 1][left - 1];
}

bool Inside(int &x, int &y)
{
    return  x >= top && x <= bot &&
            y >= left && y <= right;
}

void Add(int &x, int &y)
{
    int &id = a[x][y];
    if (used[id] || Inside(root[id].F, root[id].S)) return;

    used[id] = true;
    colors.push_back(id);
}

int Query()
{
    int res = GetSum();
    colors.clear();

    FOR(x, top, bot)
    {
        Add(x, left);
        Add(x, right);
    }

    FOR(y, left, right)
    {
        Add(top, y);
        Add(bot, y);
    }

    for (auto &id : colors) used[id] = false;
    return res + sz(colors);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> m >> n;
    FOR(i, 1, m) FOR(j, 1, n) 
    {
        cin >> a[i][j];
        root[a[i][j]] = {i, j};
    }

    FOR(i, 1, 1e6) pre[root[i].F][root[i].S] = 1;
    pre[0][0] = 0;

    FOR(i, 1, m) FOR(j, 1, n) pre[i][j] += pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];

    int q; cin >> q;
    while (q--)
    {
        cin >> top >> left >> bot >> right;
        cout << Query() << '\n';
    }

    return 0;
}