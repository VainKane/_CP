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

int const N = 36;

int m, n;
long long k;

long long a[N][N];
vector<pair<long long, int>> p1, p2;

int cnt[24][MK(20) + 5];
int limX, limY;

void Build(int stX, int stY, int m, int n, vector<pair<long long, int>> &p, int delta)
{
    REP(mask, MK(m + n))
    {
        int cnt = __builtin_popcount(mask);
        if (cnt > limX || m + n - cnt > limY) continue;

        int x = stX, y = stY;
        long long s = a[x][y];

        REP(i, m + n)
        {
            if (BIT(i, mask)) x += delta;
            else y += delta;
            s ^= a[x][y];
        }

        if (delta == -1) s ^= a[x][y];
        p.push_back({s, cnt});
    }
}

void Compress()
{
    vector<long long> vals;

    for (auto &p : p1) vals.push_back(p.F);
    for (auto &p : p2) vals.push_back(k ^ p.F);

    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());

    for (auto &p : p1) p.F = lower_bound(all(vals), p.F) - vals.begin() + 1;
    for (auto &p : p2) p.F = lower_bound(all(vals), k ^ p.F) - vals.begin() + 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> m >> n >> k;
    REP(i, m) REP(j, n) cin >> a[i][j];

    int m1 = (m - 1) / 2, m2 = (m - 1) - m1;
    int n1 = (n - 1) / 2, n2 = (n - 1) - n1;
    limX = m - 1, limY = n - 1;

    Build(0, 0, m1, n1, p1, 1);
    Build(m - 1, n - 1, m2, n2, p2, -1);

    Compress();

    long long res = 0;
    for (auto &p : p1) cnt[p.S][p.F]++;
    for (auto &p : p2) res += cnt[m - 1 - p.S][p.F];

    cout << res;

    return 0;
}