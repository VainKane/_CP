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
#define prev __prev

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
int cnt[N];

vector<int> pos[N];

int prev = 0;

int mode[BK + 5][BK + 5];
int id[N], bkId[N];

int Query(int l, int r)
{
    int idL = bkId[l];
    int idR = bkId[r];
    int res = 0;

    if (idL == idR)
    {
        FOR(i, l, r) cnt[a[i]] = 0;
        FOR(i, l, r) maxi(res, ++cnt[a[i]]);
        return res;
    }

    res = mode[idL + 1][idR - 1];
    FOR(i, l, (idL + 1) * BK - 1)
    {
        int j = id[i] + res - 1;
        while (++j < sz(pos[a[i]]) && pos[a[i]][j] <= r) res++;
    }

    FOR(i, idR * BK, r)
    {
        int j = id[i] - res + 1;
        while (--j >= 0 && pos[a[i]][j] >= l) res++;
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    REP(i, n) cin >> a[i], pos[a[i]].push_back(i);
    
    FOR(i, 1, 2e5) sort(all(pos[i]));
    
    REP(i, n) 
    {
        id[i] = lower_bound(all(pos[a[i]]), i) - pos[a[i]].begin();
        bkId[i] = i / BK;
    }

    REP(l, BK) 
    {
        memset(cnt, 0, sizeof cnt);
        int ma = 0;

        FOR(i, l * BK, n - 1) 
        {
            maxi(ma, ++cnt[a[i]]);
            maxi(mode[l][bkId[i]], ma);
        }
    }

    while (q--)
    {
        int l, r;
        cin >> l >> r;

        l = (l + prev) % n;
        r = (r + prev) % n;

        if (l > r) swap(l, r);

        prev = Query(l, r);
        cout << prev << '\n';
    }

    return 0;
}