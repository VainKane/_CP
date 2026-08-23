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

int const N = 409;

int n;
int a[N][N];

int cnt[2][N * N];
ii mx1[2], mx2[2];

void Add(int i, int j)
{
    int k = (i + j) & 1;
    int c = a[i][j];

    if (++cnt[k][c] > mx1[k].F)
    {
        if (mx1[k].S != c) mx2[k] = mx1[k];
        mx1[k] = {cnt[k][c], c};
    }

    else if (cnt[k][c] > mx2[k].F) mx2[k] = {cnt[k][c], c};
}

void Compress()
{
    vector<int> vals;
    FOR(i, 1, n) FOR(j, 1, n) vals.push_back(a[i][j]);

    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());

    FOR(i, 1, n) FOR(j, 1, n) a[i][j] = lower_bound(all(vals), a[i][j]) - vals.begin() + 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) FOR(j, 1, n) cin >> a[i][j];

    Compress();

    FOR(i, 1, n)
    {
        REP(r, 2)
        {
            memset(cnt[r], 0, sizeof cnt[r]);
            mx1[r] = mx2[r] = {0, 0};
        }

        FOR(j, 1, n)
        {
            FOR(k, 1, i) Add(k, j);

            int c1 = i * j / 2, c0 = i * j - c1;

            int res0 = c0 - mx1[0].F + c1 - (mx1[1].S == mx1[0].S ? mx2[1].F : mx1[1].F);
            int res1 = c0 - (mx1[0].S == mx1[1].S ? mx2[0].F : mx1[0].F) + c1 - mx1[1].F;

            cout << min(res0, res1) << ' ';
        }

        cout << '\n';
    }

    return 0;
}