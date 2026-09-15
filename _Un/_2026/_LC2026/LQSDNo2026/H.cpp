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

int const N = 3009;

int n, q;
bool a[N][N];

int f1[N][N][2], f2[N][N][2];

bool CheckF1(int x, int y, int h, int c)
{
    if (f1[x][y][c] > h)
    {
        FOR(k, 1, 2) if (min(f1[x][y + k][c ^ 1], f1[x + k][y][c ^ 1]) <= h - k) return false;
        return true;
    }

    return false;
}

bool CheckF2(int x, int y, int h, int c)
{
    if (f2[x][y + h][c] > h)
    {
        FOR(k, 1, 2) if (min(f2[x][y + h - k][c ^ 1], f2[x + k][y + h][c ^ 1]) <= h - k) return false;
        return true;
    }

    return false;
}

bool Check(int x, int y, int h)
{
    REP(c, 2) if (CheckF1(x, y, h, c) || CheckF2(x, y, h, c)) return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    FOR(i, 1, n) FOR(j, 1, n)
    {
        char ch; cin >> ch;
        a[i][j] = ch - '0';
    }

    FORD(i, n, 1) FORD(j, n, 1) REP(k, 2) f1[i][j][k] = a[i][j] == k ? f1[i + 1][j + 1][k] + 1 : 0;
    FORD(i, n, 1) FOR(j, 1, n) REP(k, 2) f2[i][j][k] = a[i][j] == k ? f2[i + 1][j - 1][k] + 1 : 0;

    while (q--)
    {
        int h, x, y;
        cin >> h >> x >> y;
        x++, y++;

        cout << Check(x, y, h) << '\n';
    }

    return 0;
}