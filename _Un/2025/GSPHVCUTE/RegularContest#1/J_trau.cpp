#include <bits/stdc++.h>

using namespace std;

#define name "password"

int const N = 55;

int n;
int a[N];
int cntA[N];
int cntB[N];

string res = "";

int bit(int i, int mask)
{
    return (mask >> i) & 1;
}

int Count(int l, int r, int cnt[])
{
    if (l == 0) return cnt[r];
    return cnt[r] - cnt[l - 1];
}

void Cal(int mask)
{
    memset(cntA, 0, sizeof cntA);
    memset(cntB, 0, sizeof cntB);
    string s = "";

    for (int i = 0; i < n; i++)
    {
        if (i >= 1) 
        {
            cntA[i] = cntA[i - 1];
            cntB[i] = cntB[i - 1];
        }
        if (bit(i, mask)) 
        {
            s += "a";
            cntA[i]++;
        }
        else 
        {
            s += "b";
            cntB[i]++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n - i; j++)
        {
            cnt += (Count(j, j + i, cntA) == i + 1);
            cnt += (Count(j, j + i, cntB) == i + 1);
        }
        if (cnt != a[i]) return;
    }

    if (res > s) res = s;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".ans", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    
    for (int i = 0; i < n; i++) res += "c";
    for (int mask = 0; mask < (1 << n); mask++) Cal(mask);

    for (auto ch : res) if (ch == 'c') res = "No solution.";

    cout << res;
    cerr << res << '\n';

    return 0;
}