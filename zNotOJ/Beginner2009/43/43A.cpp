#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define F first
#define S second

int const N = 5009;
double const eps = 1e-7;

int n;
pair<double, double> a[N];
pair<double, double> b[N];

double s;

double Cal(pair<double, double> a[], int n)
{
    double res = 0;
    FOR(i, 1, n) res += a[i].F * a[i + 1].S - a[i + 1].F * a[i].S;
    return 0.5 * abs(res);
}

double Split(double x)
{
    int stage = 0;
    int cnt = 0;

    FOR(i, 1, n)
    {
        if (a[i].F <= x) b[++cnt] = a[i];
        if ((a[i].F < x && a[i + 1].F > x) || (a[i + 1].F < x && a[i].F > x))
        {
            int A = a[i].S - a[i + 1].S;
            double B = a[i + 1].F - a[i].F;    
            long long C = -A * a[i].F - B * a[i].S;

            double y = (-C - A * x) / B;

            b[++cnt] = {x, y};
            stage++;
        }
    }

    b[cnt + 1] = b[1];
    return (Cal(b, cnt));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> a[i].F >> a[i].S;
    
    a[n + 1] = a[1];
    s = Cal(a, n);

    double l = -1e6;
    double r = 1e6;

    while (r - l > eps)
    {
        double mid = (l + r) / 2;
        double area = Split(mid);
        if (area < s / 2) l = mid;
        else r = mid;
    }
    cout << fixed << setprecision(4) << (l + r) / 2 << '\n';


    return 0;
}