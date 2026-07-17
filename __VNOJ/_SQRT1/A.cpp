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

int const N = 2e5 + 5;
int const BK = sqrt(N);

int n, q;

int a[N];
long long sum[BK + 5];

void Update(int idx, int val)
{
    int id = idx / BK;
    
    sum[id] -= a[idx];
    a[idx] = val;
    sum[id] += a[idx];
}

long long GetSum(int l, int r)
{
    long long res = 0;

    int idL = l / BK;
    int idR = r / BK;

    if (idL == idR)
    {
        FOR(i, l, r) res += a[i];
        return res;
    }

    FOR(i, l, (idL + 1) * BK - 1) res += a[i];
    FOR(i, idR * BK, r) res += a[i];
    FOR(i, idL + 1, idR - 1) res += sum[i];

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    REP(i, n) cin >> a[i];

    REP(i, n) sum[i / BK] += a[i];

    while (q--)
    {
        int type, l, r;
        cin >> type >> l >> r;

        if (type == 1) Update(l - 1, r);
        else cout << GetSum(l - 1, r - 1) << '\n';
    }

    return 0;
}