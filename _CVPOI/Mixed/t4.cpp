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

int const MOD = 1e9 + 7;
int const LOG = 19;

void Add(int &x, int const &y)
{
    x += y;
    if (x >= MOD) x -= MOD;
}

void Sub(int &x, int const &y)
{
    x -= y;
    if (x < MOD) x += MOD;
}

int n;
int cnt[20][MK(LOG)];
int f[36];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    int pre = 0;
    FOR(i, 1, n)
    {
        int x; cin >> x;
        pre += x;

        FOR(i, 0, LOG)
        {
            int r = pre % MK(i);
            Add(f[i], cnt[i][r]);
            Add(f[i], r == 0);
            cnt[i][r]++;
        }
    }

    int res = 0;
    FORD(i, LOG, 0)
    {
        FOR(j, i + 1, LOG) Sub(f[i], f[j]);
        res = (res + 1LL * f[i] * MK(i)) % MOD;
    }

    cout << res;

    return 0;
}