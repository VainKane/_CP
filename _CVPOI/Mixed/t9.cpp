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
#define name "smarket"

using ll = long long;
using ii = pair<int, int>;

template <class T> bool maxi(T &x, T const &y) { return x < y ? x = y, 1 : 0; }
template <class T> bool mini(T &x, T const &y) { return x > y ? x = y, 1 : 0; }

mt19937_64 rd(time(0));
ll Rand(ll l, ll r) { return rd() * 1LL * rd() % (r - l + 1); }

struct Point
{
    double x, y;
    Point(double _x = 0, double _y = 0) { x = _x, y = _y; }
    void Input() { cin >> x >> y; }
};

void Equa(Point A, Point B, double &a, double &b, double &c)
{
    a = A.y - B.y, b = B.x - A.x;
    c = -a * A.x -b * A.y;
}

Point Inter(Point A, Point B, Point C, Point D)
{
    double a1, b1, c1, a2, b2, c2;
    Equa(A, B, a1, b1, c1);
    Equa(C, D, a2, b2, c2);

    double x = (-c2 -b1 * c1) / (a2 * b1 - a1 * b1);
    double y = (-c1 - x) / b1;

    return {x, y};
}

int const N = 1009;

int n, k;
Point p[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen(name".inp", "r", stdin);
    // freopen(name".out", "w", stdout);

    cin >> n >> k;
    FOR(i, 1, n) p[i].Input();
    REP(haha, k)
    {
        auto lmao = Inter(p[Rand(1, n)], Rand(1, n) p[Rand(1, n)]);
        cout << lmao.x << ' ' << lmao.y << '\n';
    }

    return 0;
}