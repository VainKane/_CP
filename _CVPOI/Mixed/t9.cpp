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

int const N = 1009;
ll const oo = 1e18;

int n, k;

double x[N], y[N];
double centX[N], centY[N];

ll sumX[N], sumY[N];
int cnt[N];

double cx[N], cy[N];

double Dist(int i, int id)
{
    double a = x[i] - centX[id];
    double b = y[i] - centY[id];
    return a * a + b * b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> k;
    FOR(i, 1, n) cin >> x[i] >> y[i];

    double res = oo;
    REP(haha, 435)
    {
        FOR(i, 1, k) centX[i] = x[Rand(1, n)], centY[i] = y[Rand(1, n)];

        REP(hihi, max(5, (int)1e6 / n / k))
        {
            FOR(i, 1, k) sumX[i] = sumY[i] = cnt[i] = 0;
            FOR(i, 1, n)
            {
                double d = oo;
                int id = 0;

                FOR(j, 1, k) if (mini(d, Dist(i, j))) id = j;
                sumX[id] += x[i], sumY[id] += y[i];
                cnt[id]++;
            }

            FOR(i, 1, k)
            {
                if (cnt[i])
                {
                    centX[i] = (double)sumX[i] / cnt[i];
                    centY[i] = (double)sumY[i] / cnt[i];
                }
                else centX[i] = x[Rand(1, n)], centY[i] = y[Rand(1, n)];
            }
        }

        double cost = 0;
        FOR(i, 1, n)
        {
            double d = oo;
            int id = 0;

            FOR(j, 1, k) if (mini(d, Dist(i, j))) id = j;
            assert(id);
            cost += sqrt(d);
        }

        if (mini(res, cost)) FOR(i, 1, k) cx[i] = centX[i], cy[i] = centY[i];
    }

    FOR(i, 1, k) cout << fixed << setprecision(7) << cx[i] << ' ' << cy[i] << '\n';

    return 0;
}