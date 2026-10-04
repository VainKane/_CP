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

int n;
ll pre[N][2];
int d[N];

int cnt[N];

void Compress()
{
    vector<ll> vals;

    FOR(i, 0, n) vals.push_back(pre[i][0] - pre[i][1]);
    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());

    FOR(i, 0, n) d[i] = lower_bound(all(vals), pre[i][0] - pre[i][1]) - vals.begin() + 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n)
    {
        int x; cin >> x;
        REP(j, 2) pre[i][j] = pre[i - 1][j];
        pre[i][i & 1] += x;
    }

    Compress();
    cnt[d[0]] = 1;

    ll res = 0;
    FOR(i, 1, n) res += cnt[d[i]]++;
    cout << res;

    return 0;
}