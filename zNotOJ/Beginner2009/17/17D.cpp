#include <bits/stdc++.h>

using namespace std;

int const MOD1 = 1e9 + 7;
int const MOD2 = 1e8;
long long const MM1 = 1ll * MOD1 * MOD1;
long long const MM2 = 1ll * MOD2 * MOD2;
int const Base = 199;

int const N = 50009 * 2;

string s1;
string s2;

int n;

pair<int, long long> preHash1[N];
pair<int, long long> preHash2[N];
int powB1[N];
int powB2[N];

set<pair<int, int>> mark;

pair<int, int> GetHash1(int l, int r)
{
    int a = ( preHash1[r].first - 1ll * preHash1[l - 1].first * powB1[r - l + 1] + MM1 ) % MOD1; 
    int b = ( preHash1[r].second - 1ll * preHash1[l - 1].second * powB2[r - l + 1] + MM2 ) % MOD2;

    return {a, b};
}

pair<int, int> GetHash2(int l, int r)
{
    int a = ( preHash2[r].first - 1ll * preHash2[l - 1].first * powB1[r - l + 1] + MM1 ) % MOD1; 
    int b = ( preHash2[r].second - 1ll * preHash2[l - 1].second * powB2[r - l + 1] + MM2 ) % MOD2;

    return {a, b};
}

bool Check(int length)
{
    mark = set<pair<int, int>> ();

    for (int i = 1; i <= n - length + 1; i++)
    {
        mark.insert(GetHash1(i, i + length - 1));
    }
    for (int i = 1; i <= n - length + 1; i++)
    {
        pair<int, int> a = GetHash2(i, i + length - 1);
        if (mark.count(GetHash2(i, i + length - 1)) != 0) return true;
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> s1;
    cin >> s2;

    s1 = " " + s1 + s1;
    s2 = " " + s2 + s2;

    n = s1.size() - 1;

    for (int i = 1; i <= n; i++)
    {
        int a = ( 1ll * preHash1[i - 1].first * Base + s1[i] ) % MOD1;
        int b = ( 1ll * preHash1[i - 1].second * Base + s1[i] ) % MOD2;

        preHash1[i] = {a, b};
    }

    for (int i = 1; i <= n; i++)
    {
        int a = ( 1ll * preHash2[i - 1].first * Base + s2[i] ) % MOD1;
        int b = ( 1ll * preHash2[i - 1].second * Base + s2[i] ) % MOD2;

        preHash2[i] = {a, b};
    }

    powB1[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        powB1[i] = ( 1ll * powB1[i - 1] * Base ) % MOD1;
    }

    powB2[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        powB2[i] = ( 1ll * powB2[i - 1] * Base ) % MOD2;
    }

    int l = 0;
    int r = 50000 * 2;
    int res = 0;

    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (Check(mid))
        {
            res = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }

    cout << min(res, n / 2);

    return 0;
}