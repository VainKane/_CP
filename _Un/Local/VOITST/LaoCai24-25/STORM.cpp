#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define name "STORM"

int const N = 1e5 + 5;

int n, t, s, k;

int a[N];
long long pre[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> t >> s >> k;
    FOR(i, 1, n) cin >> a[i];

    sort(a + 1, a + n + 1);
    FOR(i, 1, n) pre[i] = pre[i - 1] + a[i];

    int rMax = max(0, (t - s) / k);

    int qr; cin >> qr;
    while (qr--)
    {
        int h; cin >> h;

        int numAuto = 0;
        while (a[n] > h && )
    }

    return 0;
}