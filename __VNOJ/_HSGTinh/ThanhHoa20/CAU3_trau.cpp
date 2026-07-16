#include <bits/stdc++.h>

using namespace std;

#define name "CAU3"

int const N = 1e5 + 5;

string s;
int a[N];
int p[N];

long long res = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".ans", "w", stdout);

    cin >> s;

    int n = s.size();
    s = " " + s;

    for (int i = 1; i <= n; i++) a[i] = s[i] - '0';
    for (int i = 1; i <= n; i++) p[i] = p[i - 1] + a[i];

    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            int k = p[j] - p[i - 1];
            if (i == 1 && j == n) continue;
            if ((p[n] - k) % 3 == 0)
            {
                res++;
                // cout << i << ' ' << j << '\n';
            }
        }
    }  

    res += (p[n] % 3 == 0);
    cout << res;

    return 0;
}