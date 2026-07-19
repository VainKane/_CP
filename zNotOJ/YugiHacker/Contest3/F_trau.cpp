#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define all(v) v.begin(), v.end()
#define name "nearest"

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 5e5 + 5;

int n, q;
int a[N];

int last[N];
int l[N], r[N];

void Compress()
{
    vector<int> vals;

    FOR(i, 1, n) vals.push_back(a[i]);
    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());

    FOR(i, 1, n) a[i] = lower_bound(all(vals), a[i]) - vals.begin() + 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".ans", "w", stdout);

    cin >> n >> q;
    FOR(i, 1, n) cin >> a[i];

    Compress();

    FOR(i, 1, n) 
    {
        l[i] = last[a[i]];
        last[a[i]] = i; 
    }
    
    while (q--)
    {
        int u, v;
        cin >> u >> v;
    
        int res = N;
        FOR(i, u, v) if (l[i] >= u) mini(res, i - l[i]);
        if (res == N) res = -1;
        
        cout << res << '\n';
    }

    return 0;
}