#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, a, b) for (int i = (a), _b = (b); i >= _b; i--)
#define name "SWAP"

int const N = 1e5 + 5;

int n, k;
int a[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> k;
    FOR(i, 1, n) cin >> a[i];

    FOR(i, 1, n)
    {
        if (!k) break;
        int idx = i;

        FOR(j, i + 1, n) if (a[idx] < a[j] && j - i <= k) idx = j;
        if (idx == i) continue;

        FORD(u, idx, i + 1) swap(a[u], a[u - 1]);
        k -= idx - i;
    }

    FOR(i, 1, n) cout << a[i] << ' ';
    // cout << '\n' << k;

    return 0;
}