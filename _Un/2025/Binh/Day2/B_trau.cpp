#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define F first
#define S second

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

int const N = 2009;

int n;
pair<int, int> x[N];

double Dist(pair<int, int> a, pair<int, int> b)
{
    int x = a.F - b.F;
    int y = a.S - b.S;

    return sqrt(1ll * x * x + 1ll * y * y);
}

double Area(double a, double b, double c)
{
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> x[i].F >> x[i].S;

    double res = 0;

    FOR(i, 1, n) FOR(j, i + 1, n) FOR(u, j + 1, n) FOR(v, u + 1, n)
    {
        double s1 = Area(Dist(x[i], x[j]), Dist(x[j], x[u]), Dist(x[u], x[i]));
        double s2 = Area(Dist(x[u], x[v]), Dist(x[v], x[i]), Dist(x[i], x[u]));
        maxi(res, s1 + s2);
    }

    cout << fixed << setprecision(1) << res;

    return 0;
}