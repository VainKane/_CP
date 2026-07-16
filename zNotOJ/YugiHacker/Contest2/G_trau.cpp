#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define name "dayso"

int const N = 5e4 + 5;
int const oo = N;

int n, q;
int a[N];
long long cnt[1001][N];

int mi, ma;

void Init()
{
    mi = *min_element(a + 1, a + n + 1);
    ma = *max_element(a + 1, a + n + 1);

    FOR(i, 1, n) FOR(x, mi, ma)
        cnt[x][i] = cnt[x][i - 1] + (a[i] == x);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".ans", "w", stdout);

    cin >> n >> q;
    FOR(i, 1, n) cin >> a[i];

    Init();

    while (q--)
    {
        int x, y, u, v;
        cin >> x >> y >> u >> v;

        long long res = 0;
        FOR(i, mi, ma) 
            res += 1ll * (cnt[i][v] - cnt[i][u - 1]) * (cnt[i][y] - cnt[i][x - 1]);
        cout << res << '\n';
    }

    return 0;
}