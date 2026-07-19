#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 5;

int n;
string s;
int z[N];
int p[N];
int f[N];
int a[N];

void KMP()
{
    int k = 0;
    p[0] = -1;

    for (int i = 2; i <= n; i++)
    {
        while (k >= 0 && s[k + 1] != s[i]) k = p[k];
        p[i] = ++k;
    }

    for (int i = 1; i <= n; i++) f[i] = 1;
    for (int i = n; i >= 1; i--)
    {
        f[p[i]] += f[i];
    }
}

void Z()
{
    int l = 0;
    int r = 0;

    for (int i = 2; i <= n; i++)
    {
        if (i <= r) z[i] = min(z[i - l + 1], r - i + 1);
        while (i + z[i] <= n && s[i + z[i]] == s[z[i] + 1]) z[i]++;

        if (r < i + z[i] - 1)
        {
            l = i;
            r = i + z[i] - 1;
        }

        a[z[i]]++;
    }

    // sort(z + 1, z + n + 1);
    // for (int i = 1; i <= n; i++) 
    // {
    //     f[i] = n - (lower_bound(z + 1, z + n + 1, i) - z) + 1;
    // }

    for (int i = n; i >= 1; i--) f[i] = f[i + 1] + a[i];
    for (int i = 1; i <= n; i++) f[i]++;

    // for (int i = 1; i <= n; i++) cout << f[i] + 1<< ' ';
    // cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> s;

    s = " " + s;
    n = s.size() - 1;
    
    Z();
    for (int i = 1; i <= n; i++) cout << f[i] << ' ';

    return 0;
}