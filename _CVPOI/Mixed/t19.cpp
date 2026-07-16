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
int const oo = 2e9;

int n;

int a[N];
int s = 0;

bool Check(double k)
{
    double sum = 0, ma = -oo;
    FOR(i, 2, n - 1)
    {
        sum += a[i] - k;
        maxi(ma, sum);
        if (sum < 0) sum = 0;
    }

    return ma >= s - k * n;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> a[i], s += a[i];

    double l = 0, r = 1e9;
    double res = r;

    REP(haha, 45)
    {
        double mid = (l + r) / 2;
        if (Check(mid)) r = res = mid;
        else l = mid;
    }

    cout << fixed << setprecision(4) << res;

    return 0;
}