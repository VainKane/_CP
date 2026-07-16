#include <bits/stdc++.h>

using namespace std;

int const N = 35;

int n, k;
int m;

int c[N][N];

int bit(int i, int mask)
{
    return (mask >> i) & 1;
}

void Init()
{
    c[0][0] = 1;

    for (int i = 1; i <= 30; i++)
    {
        for (int k = 0; k <= i; k++)
        {
            if (k == 0) c[k][i] = 1;
            else c[k][i] = c[k - 1][i - 1] + c[k][i - 1];
        }
    }
}

void Solve()
{
    for (int i = 31; i >= 0; i--)
    {
        if (bit(i, n))
        {
            m = i;
            break;
        }
    }

    int res = 0;
    int cnt = 0;
    
    for (int i = m - 1; i >= 0; i--) res += c[k][i];

    for (int i = m - 1; i >= 0; i--)
    {
        if (cnt > k) break;
        if (bit(i, n)) 
        {
            if (cnt < k) res += c[k - cnt - 1][i];
        }
        else cnt++;
    }

    res += (cnt == k);

    cout << res << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    Init();
    while (cin >> n >> k)
    {
        if (n == 0 && k == 0) return 0;
        Solve();
    }

    return 0;
}