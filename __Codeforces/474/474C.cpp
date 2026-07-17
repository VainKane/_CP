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

struct Point
{
    int x, y;

    Point operator + (Point const other) const
    {
        return Point {x + other.x, y + other.y};
    }

    Point operator - (Point const other) const
    {
        return Point {x - other.x, y - other.y};
    }

    bool operator == (Point const other) const
    {
        return x == other.x && y == other.y;
    }
    
    bool operator < (Point const other) const
    {
        if (x == other.x) return y < other.y;
        return x < other.x;
    }

    void Input()
    {
        cin >> x >> y;
    }

    void Print()
    {
        cout << x << ' ' << y << '\n';
    }

    void RotateO()
    {
        Point tmp = *this;
        x = -tmp.y;
        y = tmp.x;
    }

    Point Rotate(Point &center, int &t) const
    {
        Point res = *this;
        REP(i, t)
        {
            res = res - center;
            res.RotateO();
            res = center + res;
        }
        return res;
    }
};

Point ct[4], p[4];
Point pt[4];

int Dist(Point A, Point B)
{
    Point AB = B - A;
    return AB.x * AB.x + AB.y * AB.y;
}

bool Check()
{
    vector<int> d;
    REP(i, 4) FOR(j, i + 1, 3) 
    {
        if (pt[i] == pt[j]) return false;
        d.push_back(Dist(pt[i], pt[j]));
    }

    sort(all(d));
    d.erase(unique(all(d)), d.end());

    return sz(d) == 2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    while (n--)
    {
        REP(i, 4) 
        {
            p[i].Input();
            ct[i].Input();
        }

        int res = 36;
        REP(i, 5) REP(j, 5) REP(u, 5) REP(v, 5)
        {
            pt[0] = p[0].Rotate(ct[0], i);
            pt[1] = p[1].Rotate(ct[1], j);
            pt[2] = p[2].Rotate(ct[2], u);
            pt[3] = p[3].Rotate(ct[3], v);

            if (Check()) mini(res, i + j + u + v);
        }

        if (res == 36) res = -1;
        cout << res << '\n';
    }

    return 0;
}