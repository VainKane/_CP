#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

int const N = 1e4 + 5;
double const Pi = 3.1415926535;

struct Point
{
    int x, y;

    bool operator < (Point other)
    {
        if (x != other.x) return x < other.x;
        return y < other.y;
    }

    int operator * (Point other)
    {
        return x * other.y - y * other.x;
    }
};

int n, r;
Point a[N], b[N];

int m = 0;
double res = 0;

Point Vector(Point A, Point B)
{
    return Point {B.x - A.x, B.y - A.y};
}

bool cmp(Point A, Point B)
{
    int p = Vector(a[1], A) * Vector(a[1], B);
    if (p) return p > 0;
    return A < B;
}

void Graham()
{
    sort(a + 1, a + n + 1);
    sort(a + 2, a + n + 1, cmp);

    b[++m] = a[1];
    FOR(i, 2, n)
    {
        while (m > 1 && Vector(b[m - 1], b[m]) * Vector(b[m - 1], a[i]) <= 0) m--;
        b[++m] = a[i];
    }

    b[m + 1] = b[1];
}

double Dis(Point A, Point B)
{
    int x = A.x - B.x;
    int y = A.y - B.y;
    return sqrt(x * x + y * y);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> r;
    FOR(i, 1, n) cin >> a[i].x >> a[i].y;

    Graham();

    FOR(i, 1, m) res += Dis(b[i], b[i + 1]);
    res += 2 * Pi * r;
    
    cout << fixed << setprecision(3) << res;

    return 0;
}