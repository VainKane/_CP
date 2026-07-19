#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

int const N = 1e5 + 5;

int n;
int a[N];

long long pre[N], pre1[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n)
    {
        pre[i] = pre[i - 1] + a[i];
        pre1[i] = pre1[i - 1] + a[i] * (i & 1);
    }

    long long res = 0;
    
    FOR(i, 1, n) FOR(j, 1, i) 
    {
        long long s = pre[i] - pre[j - 1];
        long long s1 = pre1[i] - pre1[j - 1];
        res += s == 2 * s1;

        // if (s == 2 * s1) cout << i << ' ' << j << '\n';
    }

    cout << res;

    return 0;
}