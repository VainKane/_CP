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
#define name "SLIME"

using ll = long long;
using ii = pair<int, int>;

template <class T> bool maxi(T &x, T const &y) { return x < y ? x = y, 1 : 0; }
template <class T> bool mini(T &x, T const &y) { return x > y ? x = y, 1 : 0; }

int const N = 5e5 + 5;

ll Ceil(ll a, ll b) { return (a + b - 1) / b; }

int n, k, x;
ll l[N], r[N];

int d[3 * N], pre[3 * N];
vector<ll> vals;

void Compress()
{
    FOR(i, 1, n) if (l[i])
    {
        vals.push_back(l[i]);
        vals.push_back(r[i]);
        vals.push_back(r[i] + 1);
    }

    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());

    FOR(i, 1, n) if (l[i])
    {
        l[i] = lower_bound(all(vals), l[i]) - vals.begin() + 1;
        r[i] = lower_bound(all(vals), r[i] + 1) - vals.begin() + 1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> k >> x;
    FOR(i, 1, n)
    {
        int a, b, c, t;
        cin >> a >> b >> c >> t;

        l[i] = Ceil(x + 1LL * t * a, a);
        int idx = Ceil(c + 1LL * t * a, a);
        r[i] = (1LL * (idx - t) * a -x + 1LL * idx * b) / b;

        if (l[i] > idx) l[i] = 0;
        // cout << l[i] << ' ' << r[i] << '\n';
    }

    Compress();
    FOR(i, 1, n) if (l[i]) d[l[i]]++, d[r[i]]--;
    FOR(i, 1, sz(vals)) pre[i] = pre[i - 1] + d[i];

    ll res = 0;
    FOR(l, 1, sz(vals)) if (pre[l] >= k)
    {
        int r = l;
        for (; r <= sz(vals) && pre[r] >= k; r++); r--;
        res += vals[r - 1] - vals[l - 1] + 1;
        l = r;
    }

    cout << res;

    return 0;
}