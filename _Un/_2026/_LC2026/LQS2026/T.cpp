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

int const N = 2e5 + 5;
int const BK = 447;
int const GR = N / BK + 5;
int bkId[N], bkL[GR], bkR[GR];

struct SQRTRS
{
    int d[N];
    int bkSum[GR];

    SQRTRS()
    {
        memset(d, 0, sizeof d);
        memset(bkSum, 0, sizeof bkSum);
    }

    void Update(int l, int r, int x)
    {
        d[l] += x, d[r + 1] -= x;
        bkSum[bkId[l]] += x, bkSum[bkId[r + 1]] -= x;
    }

    int Get(int idx)
    {
        int res = 0;

        FOR(i, 1, bkId[idx] - 1) res += bkSum[i];
        FOR(i, bkL[bkId[idx]], idx) res += d[i];
    
        return res;
    }
};

int n = 2e5;

int sum[BK + 5];
SQRTRS sq;

void Init()
{
    FOR(i, 1, n)
    {
        int id = bkId[i] = (i - 1) / BK + 1;
        if (!bkL[id]) bkL[id] = i;
        bkR[id] = i;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    Init();

    int q; cin >> q;
    while (q--)
    {
        string qr;
        int x, k;

        cin >> qr >> x;
        if (qr != "ASK")
        {
            cin >> k;
            int delta = qr == "ADD" ? 1 : -1;

            if (k <= BK) sum[k] += delta * x;
            else for (int i = 1; i <= n; i += 2 * k) sq.Update(i, min(i + k - 1, n), delta * x);
        }
        else
        {
            int res = sq.Get(x);
            FOR(i, 1, BK) if ((x - 1) % (2 * i) < i) res += sum[i];
            cout << res << '\n';
        }
    }

    return 0;
}