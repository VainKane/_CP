#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define BIT(i, x) (((x) >> (i)) & 1)
#define MK(i) (1ll << (i))
#define all(v) v.begin(), v.end()
#define sz(v) ((int)v.size())
#define F first
#define S second
#define name "OFFOFF"

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 1e5 + 5;

int n;

int a[N];
vector<int> adj[N];

int cnt[N];

bool CheckSub1()
{
    FOR(u, 1, n) if (sz(adj[u]) > 2) return false;
    return true;
}

void Sub1()
{
    cout << *max_element(cnt + 1, cnt + n + 1) << ' ' << 0;
    exit(0);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n;
    FOR(i, 1, n) cin >> a[i], cnt[a[i]]++;
    FOR(i, 2, n)
    {
        int p; cin >> p;
        adj[p].push_back(i);
        adj[i].push_back(p);
    }

    Sub1();

    return 0;
}