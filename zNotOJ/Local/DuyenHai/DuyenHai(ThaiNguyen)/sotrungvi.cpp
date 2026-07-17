#include <bits/stdc++.h>

using namespace std;

#define name "sotrungvi"

int const N = 1e5 + 5;

int n;
int k;

int a[N];
long long bit[2 * N];

long long res = 0;

void Update(int idx, int val)
{
    while (idx <= 2 * n + 1)
    {
        bit[idx] += val;
        idx += idx & -idx;
    }
}

long long Get(int idx)
{
    long long res = 0;

    while (idx)
    {
        res += bit[idx];
        idx -= idx & -idx;
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] >= k) a[i] = 1;
        else a[i] = -1;
    }

    int pre = 0;
    Update(0 + n + 1, 1);

    for (int i = 1; i <= n; i++)
    {
        pre += a[i];
        res += Get(pre + n + 1); 
        Update(pre + n + 1, 1); // tranh khong duong
    }

    cout << res;

    return 0;
}