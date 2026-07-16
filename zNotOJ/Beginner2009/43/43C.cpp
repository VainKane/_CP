#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

int const N = 2e5 + 5;

struct Point
{
    int x = 0, y = 0;

    long long operator * (Point other)
    {
        return 1ll * x * other.y - 1ll * other.x * y;
    }
    bool operator < (Point other)
    {
        if (x != other.x) return x < other.x;
        return y < other.y;     
    }
};

Point Vector(Point A, Point B)
{
    return Point {B.x - A.x, B.y - A.y};
}

double Dis(Point A, Point B)
{
    long long x = A.x - B.x;
    long long y = A.y - B.y; 
    return sqrt(x * x + y * y);
}

int n, m = 0;
Point a[N];
Point b[N];

double p = 0;
long double s = 0;

bool cmp(Point A, Point B)
{
    long long cp = Vector(a[1], A) * Vector(a[1], B);
    if (cp) return cp > 0;
    return A < B;
}

void Graham()
{
    sort(a + 1, a + n + 1);
    sort(a + 2, a + n + 1, cmp);

    b[++m] = a[1];
    FOR(i, 2, n)
    {
        while (m > 1 && (Vector(b[m - 1], b[m]) * Vector(b[m - 1], a[i]) <= 0)) m--;
        b[++m] = a[i];
    }
    b[m + 1] = b[1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> a[i].x >> a[i].y;

    Graham();

    FOR(i, 1, m)
    {
        s += b[i] * b[i + 1];
        p += Dis(b[i], b[i + 1]);
    }

    cout << fixed << setprecision(3) << m << '\n' << p << '\n' << s / 2;

    return 0;
}