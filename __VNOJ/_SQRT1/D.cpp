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
    int x, y, id;

    void Input(int _id)
    {
        id = _id;
        cin >> x >> y;
    }

    bool operator < (Point const other) const
    {
        if (x == other.x) return y < other.y;
        return x < other.x;
    }
};

int const N = 1e6 + 5;

int n;
Point a[N];

bool cmp1(Point a, Point b)
{
    return a.y < b.y;
}

bool cmp2(Point a, Point b)
{
    return a.y > b.y;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) a[i].Input(i);

    sort(a + 1, a + n + 1);

    int idx = 1;
    FOR(i, 1, 1000)
    {
        vector<Point> v;
        while (idx <= n && a[idx].x <= i * 1000) v.push_back(a[idx++]);

        if (i & 1) sort(all(v), cmp1);
        else sort(all(v), cmp2);
        
        for (auto &p : v) cout << p.id << ' ';
    }

    return 0;
}