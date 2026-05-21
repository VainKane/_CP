#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

int const N = 1e5 + 5;
double const eps = 1e-7;

int n, maxW, maxH;
int a[N], b[N];

bool Check(double k)
{
    double w = 0;
    double height = 0;

    int h = b[1];

    FOR(i, 1, n)
    {
        double x = a[i] * k;

        if (x > maxW) return false;
        if (h * k > maxH) return false;

        if (b[i] == h && w + x <= maxW) w += x;
        else
        {
            height += h * k;

            w = x;
            h = b[i];
        }
    }

    height += h * k;

    return (height <= maxH);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> maxW >> maxH;
    FOR(i, 1, n) cin >> a[i] >> b[i];

    double l = 0;
    double r = 1e9;

    while (r - l > eps)
    {
        double mid = (l + r) / 2;

        if (Check(mid)) l = mid;
        else r = mid;
    }

    cout << fixed << setprecision(6) << (l + r) / 2;

    return 0;
}