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

int const N = 16;

int m, n;
ll v;

int a[N][N];
ll s[N];

ll sMask[N][MK(15) + 5];

void Init()
{
    REP(i, m) REP(j, n) s[i] += a[i][j];
    REP(j, n) REP(mask, MK(m)) for (int tmp = mask; tmp; tmp ^= tmp & -tmp)
    {
        int i = __builtin_ctz(mask);
        sMask[j][mask] += a[i][j];
    }
}

void PrintYes(int maskM, int maskN)
{
    exit(0);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> m >> n;
    REP(i, m) REP(j, n) cin >> a[i][j];

    Init();

    cin >> v;

    REP(mask, MK(m))
    {
        ll sum = 0;
        for (int tmp = mask; tmp; tmp ^= tmp & -tmp)
        {
            int i = __builtin_ctz(tmp);
            sum += s[i];
        }

        if (sum < v) continue;

        FORD(mask, MK(n) - 1, 0)
        {
            sum = 0;
            for (int tmp = mask; tmp; tmp ^= tmp & -tmp)
            {
                int i = __builtin_ctz(tmp);
                
            }
        }
    }

    return 0;
}