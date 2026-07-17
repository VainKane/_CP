#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 5;

#define name "DAYDEP"

int cnt[10 * N];
int a[N];
int n;

void Solve()
{
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] != cnt[a[i]])
        {
            cnt[a[i]]--;
            res++;
        }
    }
    cout << res;
}

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

    Solve();

    return 0;
}