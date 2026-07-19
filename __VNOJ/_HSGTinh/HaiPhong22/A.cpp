#include <bits/stdc++.h>

using namespace std;

int const N = 255;
int const B = 127;
int const MOD = 1e9 + 7;
long long const MM = 1LL * MOD * MOD;

string s;
string s1 = " virus";

int hashB = 0;
int hashA[N];
int powB[6];

int res = 0;

int GetHash(int l, int r)
{
    return ( hashA[r] - 1ll * hashA[l - 1] * powB[r - l + 1] + MM ) % MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> s;

    s = " " + s;
    int n = s.size() - 1;
    int m = s1.size() - 1;
    powB[0] = 1;

    for (int i = 1; i <= m; i++) hashB = (1ll * hashB * B + s1[i]) % MOD;
    for (int i = 1; i <= m; i++) powB[i] = (1ll * powB[i - 1] * B) % MOD;
    for (int i = 1; i <= n; i++) hashA[i] = (1ll * hashA[i - 1] * B + s[i]) % MOD;

    for (int i = 1; i <= n - m + 1; i++)
    {
        res += (GetHash(i, i + m - 1) == hashB);
    }

    cout << res;

    return 0;
}