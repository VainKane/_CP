#include <bits/stdc++.h>

using namespace std;

#define name "CAU3"

int const N = 1e5 + 5;

int n;
string s;

int cnt[10];
int a[N];
int p[N];

long long res = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> s;
    s = " " + s;
    n = s.size() - 1;

    for (int i = 1; i <= n; i++)
    {
        a[i] = s[i] - '0';
        p[i] = p[i - 1] + a[i];
    }

    int d = p[n] % 3;
    cnt[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        int k = p[i] % 3;
        // cout << i << ' ' << cnt[(k - d + 3) % 3] << '\n';
        res += cnt[(k - d + 3) % 3];
        cnt[k]++;
    }

    res += (p[n] % 3 == 0);
    cout << res - 1;

    return 0;
}