#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define all(v) v.begin(), v.end()
#define F first
#define S second

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

int const N = 1e5 + 5;
int const BASE = 256;
int const NMOD = 2;
int const MODS[] = {(int)1e9 + 2277, (int)1e9 + 5277};

struct Hash
{
    int x[NMOD];

    Hash()
    {
        memset(x, 0, sizeof x);
    }

    bool operator == (Hash const other) const
    {
        REP(k, NMOD) if (x[k] != other.x[k]) return false;
        return true;
    }

    bool operator < (Hash const other) const
    {
        REP(k, NMOD) if (x[k] != other.x[k]) return x[k] < other.x[k];
        return false;
    }
};

int n;
int a[N];
int cnt[N];

int pw[NMOD][N];
int hs[NMOD][N];

int mode = 0;

void Init()
{
    vector<int> vals;

    FOR(i, 1, n) vals.push_back(a[i]);
    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());

    FOR(i, 1, n) 
    {
        a[i] = lower_bound(all(vals), a[i]) - vals.begin() + 1;
        maxi(mode, ++cnt[a[i]]);
    }

    REP(k, NMOD)
    {
        pw[k][0] = 1;
        FOR(i, 1, n) 
        {
            pw[k][i] = 1ll * pw[k][i - 1] * BASE % MODS[k];
            hs[k][i] = (hs[k][i - 1] + 1ll * a[i] * pw[k][i - 1]) % MODS[k];
        }
    }
}

Hash GetHash(int l, int r)
{
    Hash res;

    REP(k, NMOD)
    {
        int tmp = hs[k][r] - hs[k][l - 1];
        if (tmp < 0) tmp += MODS[k];
        res.x[k] = 1ll * tmp * pw[k][n - l + 1] % MODS[k];
    }

    return res;
}

int GetPos(int const &k)
{
    vector<Hash> v;

    FOR(i, 1, n - k + 1) v.push_back(GetHash(i, i + k - 1));
    sort(all(v));

    FORD(i, n - k + 1, 1) 
    {
        Hash hs = GetHash(i, i + k - 1);
        if (upper_bound(all(v), hs) - lower_bound(all(v), hs) == mode) return i;
    }

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> a[i];

    Init();

    int l = 1;
    int r = n;
    pair<int, int> res;
    
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        int pos = GetPos(mid);
        if (pos)
        {
            res = {pos, mid};
            l = mid + 1;
        }
        else r = mid - 1;
    }

    cout << res.F << ' ' << res.F + res.S - 1;

    return 0;
}