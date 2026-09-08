#include <bits/stdc++.h>

using namespace std;

int const MOD = 1e9 + 7;
int const B = 199;
int const N = 3e5 + 10;
long long const M2 = 1ll * MOD * MOD;

string s;

int preHash[N];
int revHash[N];
int powB[N];

int n;

int GetHash(int l, int r)
{
    return (revHash[l] - 1ll * revHash[r + 1] * powB[r - l + 1] + M2) % MOD;
}

string Cal()
{
    for (int i = 1; i <= n; i++)
    {
        preHash[i] = (1ll * preHash[i - 1] * B + s[i]) % MOD;
    }
    for (int i = n; i >= 1; i--)
    {
        revHash[i] = (1ll * revHash[i + 1] * B + s[i]) % MOD;
    }

    for (int i = n; i >= 1; i--)
    {
        int hash1 = preHash[i];
        int hash2 = GetHash(1, i);

        if (hash1 == hash2)
        {
            string s1 = s.substr(i + 1, n - i);
            reverse(s1.begin(), s1.end());
            return s1 + s.substr(1, n);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> s;
    n = s.size();
    s = " " + s + " ";
    
    powB[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        powB[i] = ( 1ll * powB[i - 1] * B ) % MOD;
    }

    string s1 = Cal();
    reverse(s.begin(), s.end());
    string s2 = Cal();

    if (s1.size() < s2.size()) cout << s1;
    else if (s2 != "") cout << s2;

    return 0;
}