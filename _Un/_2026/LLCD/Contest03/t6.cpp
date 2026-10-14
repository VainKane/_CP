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

int const N = 1e5 + 5;

int n, m;
int a[N], b[N];
int cnt[N];

int facts[N][6];
int cp[N];

int pMask[N][MK(6)];

int idA[N], idB[N];
int valA[N], valB[N];

bool cmpA(int i, int j) { return valA[i] < valA[j]; }
bool cmpB(int i, int j) { return valB[i] < valB[j]; }

void Init()
{
    pMask[1][0] = 1;
    FOR(i, 2, n)
    {
        if (!cp[i]) for (int j = i; j <= n; j += i) facts[j][cp[j]++] = i;
        pMask[i][0] = 1;
        FOR(mask, 1, MK(cp[i]) - 1) pMask[i][mask] = pMask[i][mask ^ mask & -mask] * facts[i][__builtin_ctz(mask)];
    }
}

inline void Update(int i, int delta) { REP(mask, MK(cp[i])) cnt[pMask[i][mask]] += delta; }

inline int Get(int i)
{
    int res = 0;
    REP(mask, MK(cp[i])) res += __builtin_parity(mask) ? -cnt[pMask[i][mask]] : cnt[pMask[i][mask]];
    return res;
}

bool Check(int k, int x)
{
    memset(cnt, 0, (m + 1) * sizeof(int));
    FOR(i, 1, m) Update(idB[i], 1);

    int l = 0, r = 1;
    FOR(i, 1, m)
    {
        while (r <= m && valB[idB[r]] < valA[idA[i]] + x) Update(idB[r++], -1);
        while (l + 1 < r && valB[idB[l + 1]] <= valA[idA[i]] - x) Update(idB[++l], 1);

        if (Get(idA[i])) return true;
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n) cin >> b[i];

    Init();

    int l, r, res;
    FOR(k, 1, n)
    {
        l = r = m = 0;
        for (int i = k; i <= n; i += k)
        {
            maxi(r, max(a[i], b[i]));
            ++m;

            idA[m] = idB[m] = m;
            valA[m] = a[i], valB[m] = b[i];
        }

        sort(idA + 1, idA + m + 1, cmpA);
        sort(idB + 1, idB + m + 1, cmpB);

        while (l <= r)
        {
            int mid = l + r >> 1;
            if (Check(k, mid)) res = mid, l = mid + 1;
            else r = mid - 1;
        }

        cout << res << ' ';
    }

    return 0;
}