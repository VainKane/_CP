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

int n, m;
int a[N], b[N];
int cnt[N];

bool prime[N];
int facts[N][6];
int cp[N];

int pMask[N][MK(6)];

vector<int> idA[N], idB[N];
vector<int> divIdA[N], divIdB[N];

bool cmpA(int i, int j) { return a[i] < a[j]; }
bool cmpB(int i, int j) { return b[i] < b[j]; }

void Init()
{
    memset(prime, true, sizeof prime);
    prime[0] = prime[1] = false;

    FOR(i, 2, sqrt(n)) if (prime[i]) for (int j = i * i; j <= n; j += i) prime[j] = false;

    FOR(i, 1, n)
    {
        if (prime[i]) for (int j = i; j <= n; j += i) facts[j][cp[j]++] = i;
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
    int l = -1, r = 0;
    REP(i, m) Update(divIdB[k][i], 1);

    REP(i, m)
    {
        while (r < m && b[idB[k][r]] < a[idA[k][i]] + x) Update(divIdB[k][r++], -1);
        while (l + 1 < r && b[idB[k][l + 1]] <= a[idA[k][i]] - x) Update(divIdB[k][++l], 1);

        if (Get(divIdA[k][i]) > 0)
        {
            FOR(j, 0, l) Update(divIdB[k][j], -1);
            FOR(j, r, m - 1) Update(divIdB[k][j], -1);
            return true;
        }
    }

    FOR(i, 0, l) Update(divIdB[k][i], -1);
    FOR(i, r, m - 1) Update(divIdB[k][i], -1);

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

    FOR(k, 1, n)
    {
        int mx = 0;

        for (int i = k; i <= n; i += k) idA[k].push_back(i);
        idB[k] = idA[k];

        m = sz(idA[k]);
        divIdA[k] = divIdB[k] = vector<int>(m, 0);

        sort(all(idA[k]), cmpA);
        sort(all(idB[k]), cmpB);

        REP(i, m)
        {
            maxi(mx, max(a[idA[k][i]], b[idB[k][i]]));
            divIdA[k][i] = idA[k][i] / k;
            divIdB[k][i] = idB[k][i] / k;
        }

        int l = 0, r = mx;
        int res = l;

        while (l <= r)
        {
            int m1 = l + (r - l + 2) / 3;
            int m2 = r - (r - l + 2) / 3;

            if (Check(k, m2)) res = m2, l = m2 + 1;
            else if (Check(k, m1)) res = m1, l = m1 + 1, r = m2 - 1;
            else r = m1 - 1;
        }

        cout << res << ' ';
    }

    return 0;
}