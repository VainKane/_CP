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

mt19937_64 rd(time(0));
ll Rand(ll l, ll r) { return l + rd() * 1LL * rd() % (r - l + 1); }

int const N = 109;
double const oo = 6e9 + 9;

int n;
int x[N], y[N];

bool used[N];
int id[N], resId[N];

double c[N][N];

void Init()
{
    FOR(i, 1, n) FOR(j, 1, n)
    {
        int a = x[i] - x[j];
        int b = y[i] - y[j];
        c[i][j] = c[j][i] = sqrt(1LL * a * a + 1LL * b * b);
    }

    used[1] = true;

    FOR(i, 2, n)
    {
        int v = 0;
        double dist = oo;

        FOR(j, 1, n) if (!used[j] && mini(dist, c[id[i - 1]][j])) v = j;
        used[v] = true;
        id[i] = v;
    }
}

double Cost(int id[])
{
    double res = 0;
    FOR(i, 1, n) res += c[id[i]][id[i + 1]];
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> x[i] >> y[i];

    id[1] = id[n + 1] = 1;
    Init();

    FOR(i, 1, n + 1) resId[i] = id[i];
    REP(hihi, 4e4)
    {
        bool ok = false;
        FOR(u, 2, n) FOR(v, u + 2, n)
        {
            double d1 = c[id[u - 1]][id[u]] + c[id[v - 1]][id[v]];
            double d2 = c[id[u - 1]][id[v - 1]] + c[id[u]][id[v]];
            if (d1 > d2) reverse(id + u, id + v), ok = true;
        }

        if (Cost(id) < Cost(resId)) FOR(i, 1, n + 1) resId[i] = id[i];
        if (!ok && n > 1) REP(hihi, n / 15) swap(id[Rand(2, n)], id[Rand(2, n)]);
    }

    cout << fixed << setprecision(10) << Cost(resId) << '\n';
    FOR(i, 1, n) cout << resId[i] << ' ';

    return 0;
}