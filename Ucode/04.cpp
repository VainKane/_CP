#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

int const N = 5e5 + 5;

int n, q;
int a[N];
long long pre[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    FOR(i, 1, n) cin >> a[i];

    sort(a + 1, a + n + 1);
    FOR(i, 1, n) pre[i] = pre[i - 1] + a[i];

    long long delta = 0;

    while (q--)
    {
        int x; cin >> x;
        delta += x;

        int idx = upper_bound(a + 1, a + n + 1, -delta) - a - 1;
        
        long long res = abs(pre[idx] + delta * idx);
        res += pre[n] - pre[idx] + delta * (n - idx);
    
        cout << res << '\n';
    }

    return 0;
}