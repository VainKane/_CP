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

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 1e5 + 5;
int const BK = 314;
int const GR = N / BK + 5;
int bkId[N], bkL[GR], bkR[N];

int n, q;
int a[N];

int cnt[N];
int out[N];

void Build(int id)
{
    FORD(i, bkR[id], bkL[id])
    {
        cnt[i] = 1;
        int &j = out[i] = i;

        if (j + a[j] <= bkR[id])
        {
            cnt[i] += cnt[j + a[j]];
            j = out[j + a[j]];
        }
    }
}

void Init()
{
    FOR(i, 1, n)
    {
        int id = bkId[i] = (i - 1) / BK + 1;
        if (!bkL[id]) bkL[id] = i;
        bkR[id] = i;
    }

    FORD(id, bkId[n], 1) Build(id);
}

void Update(int pos, int val)
{
    a[pos] = val;
    Build(bkId[pos]);
}

void Query(int pos)
{
    int res = 1;
    while (pos + a[pos] <= n)
    {
        res += cnt[pos + a[pos]];
        pos = out[pos + a[pos]];
    }

    cout << pos << ' ' << res << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    FOR(i, 1, n) cin >> a[i];

    Init();

    while (q--)
    {
        int type, x, y;
        cin >> type >> x;

        if (type == 0)
        {
            cin >> y;
            Update(x, y);
        }
        else Query(x);
    }

    return 0;
}