#include <bits/stdc++.h>

using namespace std;

int const MOD = 1e9 + 7;
int const BASE = 1e5 + 3;
long long const MM = 1ll * MOD * MOD;

int const N = 1e5 + 10;

int n;
int a[N];
int b[N];

int ha[N];
int hb1[N];
int hb2[N];
int powb[N];

int GetHash(int l, int r, int h[])
{
    return ( h[r] - 1ll * h[l - 1] * powb[r - l + 1] + MM ) % MOD;
}

int GetRevHash(int l, int r, int h[])
{
    return ( h[l] - 1ll * h[r + 1] * powb[r - l + 1] + MM ) % MOD;
}

vector<int> res;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("17-2A.inp", "r", stdin);
    // freopen("17-2A.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    powb[0] = 1;
    for (int i = 1; i <= n; i++) 
    {
        powb[i] = ( 1ll * powb[i - 1] * BASE ) % MOD;
    }

    for (int i = 1; i <= n; i++)
    {
        ha[i] = ( 1ll * ha[i - 1] * BASE + a[i] ) % MOD;
        hb1[i] = ( 1ll * hb1[i - 1] * BASE + b[i] ) % MOD;
    }

    for (int i = n; i >= 1; i--)
    {
        hb2[i] = ( 1ll * hb2[i + 1] * BASE + b[i] ) % MOD;
    }

    for (int l = n; l >= 1; l--)
    {
        int t1 = GetHash(1, l, hb1);
        int t2 = GetHash(n - l + 1, n, ha);

        if (t1 == t2)
        {
            if (l & 1)
            {
                if (GetHash(1, n - l, ha) == GetRevHash(l + 1, n, hb2))
                {
                    res.push_back(n - l + 1);
                }
            }
            else if (GetHash(1, n - l, ha) == GetHash(l + 1, n, hb1))
            {
                res.push_back(n - l + 1);
            }
        }
    }

    cout << res.size() << '\n';
    for (auto val : res) cout << val << ' ';

    return 0;
}