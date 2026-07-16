#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define F first
#define S second
#define name "sumxor"

int const N = 1e6 + 5;

int t;
int n, q;
int a[N];

int bit[N];
int last[N];

map<int, int> mp;
vector<pii> queries[N];
int res[N];

void Update(int idx, int val)
{
    while (idx <= n)
    {
        bit[idx] ^= val;
        idx += idx & -idx;
    }
}

int GetSum(int idx)
{
    int res = 0;
    while (idx)
    {
        res ^= bit[idx];
        idx -= idx & -idx;
    }
    return res;
}

int GetSum(int l, int r)
{
    return GetSum(r) ^ GetSum(l - 1);
}

void Init()
{
    for (int i = 1; i <= n; i++)
    {
        int &x = mp[a[i]];
        last[i] = x;
        x = i;
    }

    for (int i = 1; i <= n; i++)
    {
        if (last[i]) Update(last[i], a[i]);
        for (auto p : queries[i])
        {
            res[p.S] = GetSum(p.F, i);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> t >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        int l, r;
        cin >> l >> r;
        queries[r].push_back({l, i});
    }

    Init();
    for (int i = 1; i <= q; i++) cout << res[i] << ' ';

    return 0;
}