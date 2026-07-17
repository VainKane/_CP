#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define name "29A"

typedef long long ll;

int const N = 1e5 + 5;

int n;
int a[N];
vector<int> b;

ll bit[N];
ll l[N];
ll r[N];

int d[N];

long long res = 0;

int GetSum(int x)
{
    int res = 0;

    while (x)
    {
        res += x % 10;
        x /= 10;
    }

    return res;
}

void Update(int idx, ll val)
{
    while (idx <= n)
    {
        bit[idx] = max(bit[idx], val);
        idx += idx & -idx;
    }
}

ll GetMax(int idx)
{
    ll res = 0;

    while (idx)
    {
        res = max(res, bit[idx]);
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

    cin >> n;
    for (int i = 1; i <= n; i++) 
    {
        cin >> a[i];
        d[i] = GetSum(a[i]);
        b.push_back(a[i]);
    }

    sort(all(b));
    b.erase(unique(all(b)), b.end());
    
    for (int i = 1; i <= n; i++) a[i] = lower_bound(all(b), a[i]) - b.begin() + 1;

    for (int i = 1; i <= n; i++)
    {
        Update(a[i], GetMax(a[i] - 1) + GetSum(b[a[i] - 1]));
        l[i] = GetMax(a[i]);
    }

    memset(bit, 0, sizeof bit);

    for (int i = n; i >= 1; i--) 
    {
        Update(a[i], GetMax(a[i] - 1) + GetSum(b[a[i] - 1]));
        r[i] = GetMax(a[i]);
    }

    for (int i = 1; i <= n; i++)
    {
        res = max(res, l[i] + r[i] - d[i]);
    }

    cout << res;

    return 0;
}