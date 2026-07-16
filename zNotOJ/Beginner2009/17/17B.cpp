#include <bits/stdc++.h>

using namespace std;

int const N = 2e6 + 10;
int const B = 199;
int const MOD = 1e9 + 7;
long long const M2 = 1ll * MOD * MOD;

string s;
int preHash[N];
int powB[N];

int res = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("17B.inp", "r", stdin);
    // freopen("17B.out", "w", stdout);

    cin >> s;
    int n = s.size();
    s = " " + s;

    for (int i = 1; i <= n; i++)
    {
        preHash[i] = ( 1ll * preHash[i - 1] * B + s[i] ) % MOD;
    }

    powB[0] = 1;
    for (int i = 1; i <= n - 1; i++)
    {
        powB[i] = ( 1ll * powB[i - 1] * B ) % MOD; 
    }

    int length = n / 2;
    int hash1 = ( preHash[n] - 1ll * preHash[n / 2 + 1] * powB[length] + M2 ) % MOD;
    int hash2 = preHash[length];

    for (int i = 1; i <= n / 2; i++)
    {
        int hash = preHash[i - 1];
        int tmp = ( preHash[n / 2 + 1] - 1ll * preHash[i] * powB[n / 2 + 1 - i] + M2 ) % MOD;
        hash = ( 1ll * hash * powB[n / 2 + 1 - i] + tmp ) % MOD;

        if (hash == hash1)
        {
            if (res == 0)
            {
                res = hash1;
                break;
            }
        }
    }

    for (int i = n / 2 + 1; i <= n; i++)
    {
        int hash = ( preHash[i - 1] - 1ll * preHash[n / 2] * powB[i - length - 1] + M2 ) % MOD;
        int tmp = ( preHash[n] - 1ll * preHash[i] * powB[n - i] + M2) % MOD;

        hash = (1ll * hash * powB[n - i] + tmp ) % MOD;

        if (hash == hash2)
        {
            if (res == 0)
            {
                res = hash2;
                break;
            }
            else if (hash1 != hash2)
            {
                cout << "NOT UNIQUE";
                return 0;
            }
        }
    }

    if (res == 0)
    {
        cout << "NOT POSSIBLE";
        return 0;
    }

    if (res == hash1)
    {
        for (int i = n / 2 + 2; i <= n; i++)
        {
            cout << s[i];
        }
    }
    else
    {
        for (int i = 1; i <= n / 2; i++)
        {
            cout << s[i];
        }
    }

    return 0;
}