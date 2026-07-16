#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define pii pair<int, int>
#define F first
#define S second

int const N = 1e5 + 5;
int const MOD = 1e9 + 7;

int n;
int a[N];
pii bit[N];
vector<int> b;

void Update(int idx, pii val)
{
    while (idx <= n)
    {
        if (bit[idx].F < val.F) bit[idx] = val;
        else if (bit[idx].F == val.F) 
        {
            bit[idx].S += val.S;
            bit[idx].S %= MOD;
        }
        idx += idx & -idx;
    }
}

pii GetMax(int idx)
{
    pii res = {0, 1};
    while (idx)
    {
        if (res.F < bit[idx].F) res = bit[idx];
        else if (res.F == bit[idx].F) 
        {
            res.S += bit[idx].S;
            res.S %= MOD;
        }
        idx -= idx & -idx;
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) 
    {
        cin >> a[i];
        b.push_back(a[i]);
    }

    sort(all(b));
    b.erase(unique(all(b)), b.end());  

    for (int i = 1; i <= n; i++) a[i] = lower_bound(all(b), a[i]) - b.begin() + 1;

    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        pii val = GetMax(a[i] - 1);
        val.F += 1;
        Update(a[i], val);
    }

    cout << GetMax(n).S;

    return 0;
}