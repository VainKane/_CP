#include <bits/stdc++.h>

using namespace std;

#define name "B"

int const N = 2e5 + 5;
int const MOD = 1e3 + 7;

int n, q;
int a[N];
int f[(int)1e8 + 5];

void Init()
{
    f[1] = f[2] = 1;
    for (int i = 3; i <= 1e8; i++)
    {
        f[i] = (f[i - 1] + f[i - 2]) % MOD;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".ans", "w", stdout);

    Init();

    cin >> n >> q;
    while (q--)
    {
        int type;
        int l, r;
        long long k;
        cin >> type;

        if (type == 1)
        {
            cin >> l >> r >> k;
            for (int i = l; i <= r; i++) a[i] += f[k];
        }
        else
        {
            cin >> l >> r;
            int s = 0;
            for (int i = l; i <= r; i++) s += a[i];
            cout << s << '\n';
            if (q <= 5) cerr << s << '\n';
        }
    }

    return 0;
}