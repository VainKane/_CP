#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)

template <class X, class Y>
    bool maxi(X &x, Y const &y)
    {
        if (x < y)
        {
            x = y;
            return true;
        }
        return false;
    }

template <class X, class Y>
    bool mini(X &x, Y const &y)
    {
        if (x > y)
        {
            x = y;
            return true;
        }
        return false;
    }

int const N = 509;

int m, n;

int up[N][N], down[N][N];

int Dist(int &x, int &y, int &u, int &v)
{
    int a = x - u;
    int b = y - v;
    return a * a + b * b;
}

void Update(int &x, int &y)
{
    FORD(i, x, 1) mini(down[i][y], x);
    FOR(i, x, m) maxi(up[i][y], x);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> m >> n;

    FOR(i, 1, m) FOR(j, 1, n) down[i][j] = m + 1;

    FOR(i, 1, m) FOR(j, 1, n)
    {
        char x; cin >> x;
        if (x == 'x') Update(i, j);
    }

    int q; cin >> q;
    while (q--)
    {
        int x, y;
        cin >> x >> y;

        int res = 1e9;
        FOR(j, 1, n) 
        {
            if (up[x][j]) mini(res, Dist(x, y, up[x][j], j));
            if (down[x][j] != m + 1) mini(res, Dist(x, y, down[x][j], j));
        }

        Update(x, y);
        cout << res << '\n';
    }

    return 0;
}