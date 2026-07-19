#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

int const N = 1e5 + 5;

int n;
int a[N], b[N];

long long preA[N];
long long preB[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> a[i] >> b[i];

    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);

    FOR(i, 1, n)
    {
        preA[i] = preA[i - 1] + a[i];
        preB[i] = preB[i - 1] + b[i];
    }

    long long res = 0;
    FOR(i, 1, n)
    {
        res += abs(preA[n] - preA[i - 1] - 1ll * (n - i + 1) * a[i]);
        res += abs(preB[n] - preB[i - 1] - 1ll * (n - i + 1) * b[i]);
    }

    cout << res;

    return 0;
}