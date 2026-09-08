#include <bits/stdc++.h>

using namespace std;

#define bit(i, x) (((x) >> (i)) & 1)

int const maxBit = 30;

int child[(int)3e6 + 10][2];
bool exist[(int)3e6 + 10];
int cnt = 0;

int n;
int a[(int)1e5 + 10];

void Add(int &x)
{
    int u = 0;
    for (int i = maxBit; i >= 0; i--)
    {
        int k = bit(i, x);
        if (!child[u][k]) child[u][k] = ++cnt;
        u = child[u][k];
        exist[u] = true;
    }
}

int Query(int &x)
{
    int u = 0;
    int res = 0;
    for (int i = maxBit; i >= 0; i--)
    {
        int k = bit(i, x);
        int tar = abs(1 - k);

        if (exist[child[u][tar]])
        {
            res |= (1 << i);
            u = child[u][tar];
        }   
        else if (exist[child[u][k]])
        {
            u = child[u][k];
        }
        else break;
    }

    return res;
}

int res = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        Add(a[i]);
    }

    for (int i = 1; i <= n; i++)
    {
        res = max(res, Query(a[i]));
    }

    cout << res;

    return 0;
}