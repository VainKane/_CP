#include <bits/stdc++.h>

using namespace std;

struct Point
{
    int x, y;

    long long operator * (Point other)
    {
        return 1ll * x * other.y - 1ll * y * other.x;
    }
};

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

int const N = 5e3 + 5;

int n, m;
Point a[N];

Point Vector(Point A, Point B)
{
    return Point {B.x - A.x, B.y - A.y};
}

long long Area(Point A, Point B, Point C)
{
    return abs(Vector(A, B) * Vector(A, C));
}

bool IsIn(Point A, Point B, Point C, Point P)
{   
    long long s = Area(A, B, C);
    long long s1 = Area(A, B, P);
    long long s2 = Area(A, P, C);
    long long s3 = Area(P, B, C);

    return (s == s1 + s2 + s3 && s1 != 0 && s2 != 0 && s3 != 0);
}

bool Check(Point V)
{
    int l = 2;
    int r = n;
    int k = -1;

    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (Vector(a[1], a[mid]) * Vector(a[1], V) > 0) 
        {
            k = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }

    if (k == -1) return false;
    return IsIn(a[1], a[k], a[k + 1], V);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> a[i].x >> a[i].y;
    a[n + 1] = a[1];

    cin >> m;

    while (m--)
    {
        int x, y;
        cin >> x >> y;
        cout << Check(Point {x, y}) << '\n';
    }

    return 0;
}