#include <bits/stdc++.h>

using namespace std;

#define bit(i, x) ((x >> i) & 1)

int const N = 1e5;
int const maxBit = 30;

int n;
int k;

int child[N * 30 + 2][2];
int exist[N * 30 + 2];

int cnt = 0;

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

int Query(int &x)
{
    int u = 0;
    int res = 0;
    for (int i = maxBit; i >= 0; i--)
    {
        int kBit = bit(i, k);
        int xBit = bit(i, x);

        if (kBit == 1)
        {
            res += exist[child[u][xBit]];
            if (!child[u][1 - xBit]) break;
            u = child[u][1 - xBit];
        }
        else
        {
            if (!child[u][xBit]) break;
            u = child[u][xBit];
        }
    }

    return res;
}

long long res = 0;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;

    int pre = 0;
    Add(pre);
    
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        pre ^= a;

        res += 1ll * Query(pre);
        Add(pre);
    }

    cout << res;

    return 0;
}