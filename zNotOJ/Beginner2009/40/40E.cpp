#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second

int const MOD = 1e9 + 7;
int const N = 1e4 + 5;

int n, k;

pair<int, int> a[N];
int bitt[N];

int res = 0;

vector<int> trees;

int bit(int i, int mask)
{
    return (mask >> i) & 1;
}

void Update(int idx, int val)
{
    while (idx <= 1e4)
    {
        bitt[idx] += val;
        bitt[idx] %= MOD;
        idx += idx & -idx;
    }
}

int GetSum(int idx)
{
    int res = 0;
    while (idx)
    {
        res += bitt[idx];
        res %= MOD;
        idx -= idx & -idx;
    }
    return res;
}

bool Check(int x)
{
    for (auto val : trees) if (x == val) return false;
    return true;
}

int Cal()
{
    memset(bitt, 0, sizeof bitt);
    int res = 0;

    for (int i = 1; i <= n; i++)
    {
        if (!Check(a[i].F)) continue;

        int val = (GetSum(a[i].S - 1) + 1) % MOD;
        res = (res + val) % MOD;
        Update(a[i].S, val);
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i].F >> a[i].S;

    for (int mask = 0; mask < (1 << k); mask++)
    {
        trees.clear();
        for (int i = 0; i < k; i++)
        {
            if (bit(i, mask)) trees.push_back(i + 1);
        }

        int k = __builtin_popcount(mask);
        int x = Cal();

        if (k & 1) res = (res - x + MOD) % MOD;
        else res = (res + x) % MOD;
    }

    cout << res;

    return 0;
}