#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, a, b) for (int i = (a), _b = (b); i >= _b; i--)
#define MK(i) (1 << (i))
#define name "GCD"

int const N = 2e5 + 5;
int const LOG = 18;

int n, q;
int a[N];

int up[N][22];
int lg[N];

int GCD(int a, int b)
{
    while (b)
    {
        int r = a % b;
        a = b;
        b = r;
    }

    return a;
}

void Init()
{
    FOR(i, 1, n) up[i][0] = a[i];
    FOR(j, 1, LOG) FOR(i, 1, n)
        up[i][j] = __gcd(up[i][j - 1], up[i + MK(j - 1)][j - 1]);

    FOR(i, 2, n) lg[i] = lg[i / 2] + 1;
}

int GetGCD(int l, int r)
{
    int k = lg[r - l + 1];
    return __gcd(up[l][k], up[r - MK(k) + 1][k]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> q;
    FOR(i, 1, n) cin >> a[i];

    Init();

    while (q--)
    {
        int l, r, x;
        cin >> l >> r >> x;

        long long res = 0;

        FOR(i, l, r) FOR(j, i, r)
        {
            if (GetGCD(i, j) >= x) res++;
            else break;
        }

        cout << res << '\n';
    }

    return 0;
}
