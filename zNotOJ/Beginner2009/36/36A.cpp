#include <bits/stdc++.h>

using namespace std;

int const N = 20;

int n;
int q;
int a[N];
int res[N];

bool used[N];

long long f[N];

void Query1()
{
    memset(used, 0, sizeof used);
    long long res = 0;
    for (int i = 1; i <= n; i++)
    {
        int cnt = 0;
        for (int j = 1; j < a[i]; j++) if (!used[j]) cnt++;

        res += cnt * f[n - i];
        used[a[i]] = true;
    }

    // da tinh so hv truoc do -> +1
    cout << res + 1 << '\n';
}

void Query2(long long k) 
{
    memset(used, 0, sizeof used);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (used[j]) continue;
            if (k > f[n - i]) k -= f[n - i];
            else
            {
                cout << j << ' ';
                used[j] = true;
                break;
            }
        }       
    }
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    f[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        f[i] = f[i - 1] * i;
    }

    while (cin >> q)
    {
        if (q == 1)
        {
            for (int i = 1; i <= n; i++) cin >> a[i];
            Query1();
        }
        else 
        {
            long long k; cin >> k;
            Query2(k);
        }
    }

    return 0;
}