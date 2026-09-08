#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define name "dimghinh"

struct Point
{
    int x, y;

    int operator * (Point const other) const
    {
        return x * other.y - y * other.x;
    }
};

int const N = 1e5 + 5;

int n;
Point a[N][4];

Point Vector(Point A, Point B)
{
    return Point{B.x - A.x, B.y - A.y};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".ans", "w", stdout);

    cin >> n;
    FOR(i, 1, n) REP(j, 4) cin >> a[i][j].x >> a[i][j].y;

    int res = 0;
    FOR(u, -1000, 1000) FOR(v, -1000, 1000) 
    {
        bool dg = true;
        Point C = {u, v};

        FOR(i, 1, n)
        {
            int area = 0;
            bool ok = true;

            REP(j, 4)
            {
                int s = abs(Vector(C, a[i][j]) * Vector(C, a[i][(j + 1) % 4]));
                area += s;
                
                if (s == 0) ok = false;
            }

            if (!ok)
            {
                dg = false;
                break;
            }

            if (area != 2 * abs(Vector(a[i][1], a[i][0]) * Vector(a[i][1], a[i][2])))
            {
                dg = false;
                break;
            }
        }
        res += dg;
        // if (dg == true) cout << u << ' '<< v << '\n';
    }

    cout << res;

    return 0;
}