#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define name "29B"

int const N = 1e4 + 5;
int const MOD = 1e9;

int n;
int k;
int a[N];
vector<int> b;

int bit[19][N];

void Update(int idx, int p, int val)
{
    while (idx <= n)
    {
        bit[p][idx] += val;
        bit[p][idx] %= MOD;
        idx += idx & -idx;
    }
}

int GetSum(int idx, int p)
{
    int res = 0;

    while (idx)
    {
        res += bit[p][idx];
        res %= MOD;
        idx -= idx & -idx;
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen(name".inp", "r", stdin);
    // freopen(name".out", "w", stdout);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) 
    {
        cin >> a[i];
        b.push_back(a[i]);
    }

    sort(all(b));
    b.erase(unique(all(b)), b.end());
    for (int i = 1; i <= n; i++) a[i] = lower_bound(all(b), a[i]) - b.begin() + 1;

    for (int i = n; i >= 1; i--)
    {
        Update(a[i], 1, 1);
        for (int p = 2; p <= k; p++)
        {
            Update(a[i], p, (GetSum(a[i] - 1, p - 1) + MOD) % MOD);
        }
    }

    cout << GetSum(n, k);

    return 0;
}