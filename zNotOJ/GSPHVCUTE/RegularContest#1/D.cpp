#include <bits/stdc++.h>

using namespace std;

#define name "bubbletea"

int const N = 2509;

int n;
int a[N];

bool used[N];

int res = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    sort(a + 1, a + n + 1);

    for (int i = 2; i <= n; i++)
    {
        if (a[i] - a[i - 1] <= 2 && !used[i - 1])
        {
            res++;
            used[i] = used[i - 1] = true;
        }
    }

    for (int i = 1; i <= n; i++) if (!used[i]) res++;

    cout << res;

    return 0;
}