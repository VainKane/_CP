#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)

int const N = 1e5 + 5;

int n;
int cnt[10 * N];
int a[N];

long long res[10 * N];

long long C2(int n)
{
    return 1ll * n * (n - 1) / 2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) 
    {
        int x; cin >> x;
        cnt[x]++;
    }

    FOR(i, 1, 1e6) for (int j = 2 * i; j <= 1e6; j += i) cnt[i] += cnt[j];
    FORD(i, 1e6, 1) 
    {
        res[i] = C2(cnt[i]);
        for (int j = 2 * i; j <= 1e6; j += i) res[i] -= res[j];
    }

    cout << res[1];

    return 0;
}