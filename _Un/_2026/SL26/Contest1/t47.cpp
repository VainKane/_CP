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
int const M = 1e6 + 5;

struct FenwickTree
{
    vector<int> bit;
    int n;

    FenwickTree(int _n = 0)
    {
        n = _n;
        bit.assign(n + 5, 0);
    }

    void Update(int idx, int val) { for (; idx; idx ^= idx & -idx) bit[idx] += val; }

    int Get(int idx)
    {
        int res = 0;
        for (; idx <= n; idx += idx & -idx) res += bit[idx];
        return res;
    }
};

int n;
ll a[N];

FenwickTree bit;

bool prime[M];
vector<int> primes;

vector<pair<ll, int>> pf[N];

multiset<int> s[11 * N];
int cnt[N];

void Compress()
{
    vector<ll> vals;

    FOR(i, 1, n) vals.push_back(a[i]);
    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());

    FOR(i, 1, n) a[i] = lower_bound(all(vals), a[i]) - vals.begin() + 1;
    bit = FenwickTree(sz(vals));
}

void Sieve()
{
    memset(prime, true, sizeof prime);
    prime[0] = prime[1] = false;

    FOR(i, 2, sqrt(1e6)) if (prime[i]) for (int j = i * i; j <= 1e6; j += i) prime[j] = false;
    FOR(i, 2, 1e6) if (prime[i]) primes.push_back(i);
}

vector<pair<ll, int>> Factor(ll x)
{
    vector<pair<ll, int>> f;
    int sq = sqrt(x);

    for (auto &p : primes)
    {
        if (p > sq) break;
        
        if (x % p == 0)
        {
            f.push_back({p, 0});
            while (x % p == 0) x /= p, f.back().S++;
        }
    }

    if (x > 1) f.push_back({x, 1});
    return f;
}

void Init()
{
    vector<ll> vals;

    FOR(i, 1, n)
    {
        pf[i] = Factor(a[i]);
        for (auto &p : pf[i]) vals.push_back(p.F);
    }

    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());

    FOR(i, 1, n) for (auto &p : pf[i]) p.F = lower_bound(all(vals), p.F) - vals.begin() + 1;
}

int Cal(int mask)
{
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> a[i];

    Sieve();
    Init();
    Compress();

    ll res = 0;
    FOR(i, 1, n)
    {
        bit.Update(a[i], 1);
        int inv = bit.Get(a[i] + 1);
    
        for (auto &p : pf[i]) s[p.F].insert(p.S);
        cnt[a[i]]++;

        res += inv;
    }

    cout << res;

    return 0;
}