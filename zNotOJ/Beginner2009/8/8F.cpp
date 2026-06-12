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
#define name ""

using ll = long long;
using ii = pair<int, int>;

template <class T> bool maxi(T &x, T const &y) { return x < y ? x = y, 1 : 0; }
template <class T> bool mini(T &x, T const &y) { return x > y ? x = y, 1 : 0; }

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
    double res = l;

    while (r - l > eps)
    {
        double mid = (l + r) / 2;

        if (Check(mid))
        {
            res = mid;
            l = mid;
        }
        else r = mid;
    }

    cout << fixed << setprecision(6) << res;

    return 0;
}