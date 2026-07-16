#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()

int const N = 1e5 + 5;

int n;
int a[N];
vector<int> b;

long long bit[N];
long long res = 0;

void Update(int idx, int val)
{
    while (idx <= n)
    {
        bit[idx] += val;
        idx += idx & -idx;
    }
}

long long GetSum(int idx)
{
    long long res = 0;
    while (idx)
    {
        res += bit[idx];
        idx -= idx & (-idx);
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
    
    for (int i = 1; i <= n; i++)
    {
        a[i] = lower_bound(all(b), a[i]) - b.begin() + 1;
    }

    for (int i = n; i >= 1; i--)
    {
        res += GetSum(a[i] - 1);
        Update(a[i], 1);
    }

    cout << res;

    return 0;
}