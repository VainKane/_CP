#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)

int const N = 1e6 + 5;

int n;
int a[N];

int cnt[N];
int cntDiv[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> a[i], cnt[a[i]]++;

    FOR(i, 1, 1e3) for (int j = i; j <= 1e6; j += i)
    {
        cntDiv[i] += cnt[j];
        if (i * i != j) cntDiv[j / i] += cnt[j];
    }

    FORD(i, 1e6, 1) if (cntDiv[i] >= 2)
    {
        FOR(u, 1, n) if (a[u] % i == 0) FOR(v, u + 1, n) if (a[v] % i == 0)
        {
            cout << u << ' ' << v << '\n';
            return 0;
        }
    }

    return 0;
}