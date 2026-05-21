#include <bits/stdc++.h>

using namespace std;

int const N = 3e5 + 5;

int n;
int a[N];
int z[N];
int p[N];

void ZFunc()
{
    int l = 0;
    int r = 0;

    for (int i = 2; i <= n; i++)
    {
        int x = 0;
        if (i <= r) x = min(z[i - l + 1], r - i + 1);
        while (i + x <= n && a[i + x] == a[x + 1]) x++;
        z[i] = x;
        
        if (r < i + z[i] - 1)
        {
            r = i + z[i] - 1;
            l = i;
        }

        if (z[i] == n - i + 1)
        {
            cout << i - 1;
            exit(0);
        }
    }
}

void KMP()
{
    p[0] = -1;
    int k = 0;
    for (int i = 2; i <= n; i++)
    {
        while (k >= 0 && a[k + 1] != a[i]) k = p[k];
        p[i] = ++k;
    }

    cout << n - p[n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    KMP();

    return 0;
}