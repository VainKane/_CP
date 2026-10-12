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

int const N = 2e5 + 5;

int n;
int a[N], b[N];

int cnt[2 * N];

vector<int> vals;

void Compress()
{
    vals.clear();

    FOR(i, 1, n)
    {
        vals.push_back(a[i]);
        vals.push_back(b[i]);
    }

    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());

    FOR(i, 1, n)
    {
        a[i] = lower_bound(all(vals), a[i]) - vals.begin() + 1;
        b[i] = lower_bound(all(vals), b[i]) - vals.begin() + 1;
    }
}

ll Cal(int idx)
{
    FOR(i, 1, idx) cnt[b[i]]++;

    vector<int> va, vb;
    FOR(i, 1, idx)
    {
        if (cnt[a[i]]) cnt[a[i]]--;
        else va.push_back(a[i]);
    }

    FOR(i, 1, idx) if (cnt[b[i]]) vb.push_back(b[i]);
    sort(all(va));

    ll res = 0;
    int mx = 0;
    REP(i, sz(vals))
    {
        int cost = vals[va[i] - 1] - vals[vb[i] - 1];
        maxi(mx, cost);
        res += cost;
    }

    FOR(i, 1, idx) cnt[b[i]] = 0;
    return res - mx;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--)
    {
        cin >> n;
        FOR(i, 1, n) cin >> a[i];
        FOR(i, 1, n) cin >> b[i];

        Compress();
        FOR(i, 1, n) cout << Cal(i) << ' ';
        cout << '\n';
    }

    return 0;
}