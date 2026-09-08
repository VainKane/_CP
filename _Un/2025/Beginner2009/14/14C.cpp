#include <bits/stdc++.h>

using namespace std;

#define bit(i, x) ((x >> i) & 1)
int maxBit = 30;

int child[(int)9e6 + 10][2];
int exist[(int)9e6 + 10];

int cnt = 0;

int n;

void Add(int &x)
{
    int u = 0;
    for (int i = maxBit; i >= 0; i--)
    {
        int k = bit(i, x);
        if (!child[u][k]) child[u][k] = ++cnt;
        u = child[u][k];
        exist[u]++;
    }
}

int Query(int &k)
{
    int u = 0;
    int res = 0;
    for (int i = maxBit; i >= 0; i--)
    {
        if (exist[child[u][0]] >= k)
        {
            u = child[u][0];
        }
        else
        {
            k -= exist[child[u][0]];
            res |= (1 << i);
            u = child[u][1];
        }
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("14D.inp", "r", stdin);
    // freopen("14D.out", "w", stdout);

    cin >> n;
    while (n--)
    {
        int t, x;
        cin >> t >> x;
        if (t == 1) Add(x);   
        else cout << Query(x) << '\n';
    }

    return 0;
}