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

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 3009;

int n;

char a[N][N];
int dx[] = {0, 1};
int dy[] = {1, 0}; 

vector<pair<int, int>> cur, nxt;

bool Inside(int x, int y)
{
    return  x >= 1 && x <= n &&
            y >= 1 && y <= n;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) FOR(j, 1, n) cin >> a[i][j];

    cout << a[1][1];

    cur.push_back({1, 1});
    FOR(haha, 1, 2 * n - 2)
    {
        char mi = 'Z';

        for (auto &p : cur) REP(i, 2)
        {
            int x = p.F + dx[i];
            int y = p.S + dy[i];

            if (Inside(x, y)) mini(mi, a[x][y]);
        }

        for (auto &p : cur) REP(i, 2)
        {
            int x = p.F + dx[i];
            int y = p.S + dy[i];

            if (Inside(x, y) && a[x][y] == mi) nxt.push_back({x, y});
        }

        sort(all(nxt));
        nxt.erase(unique(all(nxt)), nxt.end());

        swap(cur, nxt);
        nxt.clear();
        cout << mi;
    }

    return 0;
}