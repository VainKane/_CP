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

#pragma GCC optimize("O3,Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,abm,mmx,avx,tune=native")

int const N = 16;
int const lim = 950;

int m, n;
ll v;

int a[N][N];
ll s[N];

ll sMask[N][MK(15) + 5];
ll tsum = 0, sum = 0;
ll haha = 0;

int maskM, maskN;

void Init()
{
    REP(i, m) REP(j, n) s[i] += a[i][j];
    REP(j, n) REP(mask, MK(m)) for (int tmp = mask; tmp; tmp ^= tmp & -tmp)
        sMask[j][mask] += a[__builtin_ctz(tmp)][j];
}

void PrintAns(int maskM, int maskN)
{
    cout << __builtin_popcount(maskM) + __builtin_popcount(maskN) << '\n';
    
    for (int tmp = maskM; tmp; tmp ^= tmp & -tmp) cout << "1 " << __builtin_ctz(tmp) + 1 << '\n';
    for (int tmp = maskN; tmp; tmp ^= tmp & -tmp) cout << "2 " << __builtin_ctz(tmp) + 1 << '\n';

    exit(0);
}

void Try(int pos)
{
    if (pos == n)
    {
        if (tsum - sum - haha == v) PrintAns(maskM, maskN);
        return;
    }

    REP(i, 2)
    {
        maskN ^= MK(pos);
        haha += BIT(pos, maskN) * sMask[pos][(MK(m) - 1) ^ maskM];

        if (haha > tsum - sum - v)
        {
            haha -= BIT(pos, maskN) * sMask[pos][(MK(m) - 1) ^ maskM];
            continue;
        }
        
        Try(pos + 1);
        haha -= BIT(pos, maskN) * sMask[pos][(MK(m) - 1) ^ maskM];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> m >> n;
    REP(i, m) REP(j, n) cin >> a[i][j], tsum += a[i][j];
    cin >> v;

    Init();

    auto startTime = chrono::high_resolution_clock::now();
    for (maskM = 0; maskM < MK(m); maskM++)
    {
        if (chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - startTime).count() > lim) return !(cout << -1);

        sum = 0;
        for (int tmp = maskM; tmp; tmp ^= tmp & -tmp) sum += s[__builtin_ctz(tmp)];
        if (tsum - sum < v) continue;

        maskN = 0;
        haha = 0;
        Try(0);
    }

    cout << -1;

    return 0;
}