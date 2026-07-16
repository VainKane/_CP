#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define BIT(i, x) (((x) >> (i)) & 1)
#define MK(i) (1LL << (i))
#define ALL(v) v.begin(), v.end()
#define sz(v) ((int)v.size())
#define F first
#define S second
#define name "POST"

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

int const N = 5009;

int n, q;
int a[N];

int cnt[N][N];

int pre[N], nxt[N];
int last[N];

int pr[N][N];

void Compress()
{
    vector<int> vals;

    FOR(i, 1, n) vals.push_back(a[i]);
    sort(ALL(vals));
    vals.erase(unique(ALL(vals)), vals.end());

    FOR(i, 1, n) a[i] = lower_bound(ALL(vals), a[i]) - vals.begin() + 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> q;
    FOR(i, 1, n) cin >> a[i];

    Compress();

    FORD(i, n, 1)
    {
        nxt[i] = last[a[i]];
        last[a[i]] = i;
    }

    memset(last, 0x3f, sizeof last);

    FOR(i, 1, n)
    {
        pre[i] = last[a[i]];
        last[a[i]] = i;
    }

    FOR(l, 1, n)
    {
        int mi = pre[l];
        int ma = nxt[l];

        FOR(r, l, n)
        {
            mini(mi, pre[r]);
            maxi(ma, nxt[r]);

            cnt[l][r] = cnt[l][r - 1] + (mi >= l && ma <= r);
        }
    }

    FOR(r, 1, n) FOR(l, 1, r) pr[r][l] = pr[r][l - 1] + cnt[l][r];
    FOR(l, 1, n) FOR(r, l, n) cnt[l][r] += pr[r][r] - pr[r][l];

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << cnt[l][r] << '\n';
    }

    return 0;
}
