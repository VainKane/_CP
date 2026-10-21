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

struct FenwickTree
{
    vector<int> bit;
    int n;

    FenwickTree(int _n = 0)
    {
        n = _n;
        bit.assign(n + 5, 0);
    }

    void Update(int idx, int val) { for (; idx <= n; idx += idx & -idx) bit[idx] += val; }

    int Get(int idx)
    {
        int res = 0;
        for (; idx; idx ^= idx & -idx) res += bit[idx];
        return res;
    }
};

int n;
ll a[N];

FenwickTree bit;
vector<ll> vals;

void Compress()
{
    FOR(i, 1, n) vals.push_back(a[i]);
    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());

    FOR(i, 1, n) a[i] = lower_bound(all(vals), a[i]) - vals.begin() + 1;
    bit = FenwickTree(sz(vals));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> a[i];

    Compress();

    set<pair<ll, int>> s;
    FOR(i, 1, n) s.insert({a[i], i});

    ll res = 0;
    FORD(i, n, 1) res += bit.Get(a[i] - 1), bit.Update(a[i], 1);

    FOR(i, 1, n)
    {
        auto val = *s.begin();
        FORD(j, val.S, i + 1)
        {
            if (vals[a[j - 1] - 1] % vals[a[j] - 1]) return !(cout << -1);
            
            s.erase({a[j], j}), s.erase({a[j - 1], j - 1});
            s.insert({a[j], j - 1}), s.insert({a[j - 1], j});
            swap(a[j - 1], a[j]);
        }

        s.erase({a[i], i});
    }

    cout << res;

    return 0;
}