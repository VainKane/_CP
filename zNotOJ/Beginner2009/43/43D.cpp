#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

int const N = 1e4 + 5;

struct Point
{
    double x, y;

    double operator * (Point other)
    {
        return x * other.y - y * other.x;
    }
    bool operator != (Point other)
    {
        return (x != other.x || y != other.y);
    }
};

int n, m = 0;
Point a[N], p[N];
double S[3];

void Eql(Point A, Point B, long long &a, long long &b, long long &c)
{
    a = A.y - B.y;
    b = B.x - A.x;
    c = -a * A.x - b * A.y;
}

Point Inter(Point A, Point B)
{
    long long a1, b1, c1, a2, b2, c2;

    Eql(A, B, a1, b1, c1);
    Eql(a[1], a[n], a2, b2, c2);

    if (a1 == 0 || a1 * b2 - a2 * b1 == 0) return a[1];

    double y = (a2 * c1 - a1 * c2) / (double) (a1 * b2 - a2 * b1);
    double x = (-c1 - b1 * y) / (double) a1;

    if (x < A.x || x > B.x) return a[1];
    return Point {x, y};
}

double Area()
{
    double s = 0;
    p[m + 1] = p[1];

    FOR(i, 1, m) s += p[i] * p[i + 1];
    return abs(s) / 2;
}

void Cal()
{
    long long A, B, C;
    Eql(a[1], a[n], A, B, C);

    int k = 2;
    if (A * p[2].x + B * p[2].y + C > 0) k = 1;
    
    S[k] += Area();
    p[1] = p[m];
    m = 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> a[i].x >> a[i].y;

    p[++m] = a[1];
    FOR(i, 2, n - 1)
    {
        Point I = Inter(a[i], a[i + 1]);
        p[++m] = a[i];
        if (I != a[1]) 
        {
            p[++m] = I;
            Cal();
        }
    }

    p[++m] = a[n];
    Cal();

    cout << fixed << setprecision(4) << S[2] << '\n' << S[1];

    return 0;
}