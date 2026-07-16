#include <bits/stdc++.h>

using namespace std;

#define name "CAU2"

int const N = 1e6 + 5;

int n;
int a[N];
int cnt[N];

int res = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
    }

    for (int i = 1; i <= n; i++)
    {
        res = max(res, cnt[a[i]]);
    }

    cout << res;

    return 0;
}