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

int const N = 1e6 + 5;
int MOD;

void Add(int &x, int const &y)
{
    x += y;
    if (x >= MOD) x -= MOD;
}

int n, m;
int a[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> MOD;
    REP(i, n) cin >> a[i];

    int res = 0;
    REP(mask, MK(n)) if (mask ^ (mask & -mask))
    {
        int val = 2 * m;
        for (int tmp = mask; tmp; tmp ^= tmp & -tmp)
        {
            int i = __builtin_ctz(tmp);
            for (int haha = tmp ^ MK(i); haha; haha ^= haha & -haha)
            {
                int j = __builtin_ctz(haha);
                mini(val, a[i] ^ a[j]);
            }
        }

        res = (res + val) % MOD;
    }

    cout << res;

    return 0;
}