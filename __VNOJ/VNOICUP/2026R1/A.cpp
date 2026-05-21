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

int const N = 109;

int m, n, x, y, dx, dy;
bool visitedC[N], visitedR[N];

bool Check()
{
    bool okR = true, okC = true;
    FOR(i, 1, m) okR &= visitedR[i];
    FOR(i, 1, n) okC &= visitedC[i];
    return okR || okC;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--)
    {
        cin >> m >> n >> x >> y;

        memset(visitedC, false, sizeof visitedC);
        memset(visitedR, false, sizeof visitedR);

        dx = dy = 1;

        visitedC[y] = visitedR[x] = true;
        int cnt = 0;

        while (!Check())
        {
            if (x + dx < 1 || x + dx > m) dx = -dx;
            if (y + dy < 1 || y + dy > n) dy = -dy;

            x += dx, y += dy;
            visitedR[x] = true, visitedC[y] = true;
            cnt++;
        }

        cout << cnt << '\n';
    }

    return 0;
}