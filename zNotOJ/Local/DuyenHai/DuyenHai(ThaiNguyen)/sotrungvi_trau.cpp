#include <bits/stdc++.h>

using namespace std;

#define name "sotrungvi"

int const N = 1e5 + 5;

int n;
int k;

int a[N];
int p[N];

long long res = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".ans", "w", stdout);

    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] >= k) a[i] = 1;
        else a[i] = -1;
    }

    for (int i = 1; i <= n; i++)
    {
        p[i] = p[i - 1] + a[i];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            if (p[j] - p[i - 1] >= 0) res++;
        }
    }

    cout << res;

    return 0;
}