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
int const M = sqrt(2 * N) + 5;

int n, m;
int a[N], ct[N];

int cnt[M][N];
int req[M];
int haha = 0;

void Compress()
{
    vector<int> vals;
    FOR(i, 1, n) vals.push_back(a[i]);
    
    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());

    FOR(i, 1, n) 
    {
        a[i] = lower_bound(all(vals), a[i]) - vals.begin() + 1;
        ct[a[i]]++;
    }

    FOR(i, 1, sz(vals)) if (ct[i] >= vals[i - 1]) 
    {
        req[++haha] = vals[i - 1];
        FOR(j, 1, n) cnt[haha][j] = cnt[haha][j - 1] + (a[j] == i);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    FOR(i, 1, n) cin >> a[i];

    Compress();

    while (m--)
    {
        int l, r;
        cin >> l >> r;

        int res = 0;
        FOR(i, 1, haha) res += cnt[i][r] - cnt[i][l - 1] == req[i];
        cout << res << '\n';
    }

    return 0;
}