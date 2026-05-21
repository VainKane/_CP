#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second

int const N = 1e5 + 5;

int n, q;
int cnt = 0;

long long a[N];
vector<int> adj[N];
pair<int, int> qr[N];

int in[N];
int out[N];

pair<int, int> bd[N];
vector<int> group[N];

long long bit[N];
int res[N];

void Update(int idx, int val)
{
    while (idx <= n)
    {
        bit[idx] += val;
        idx += idx & -idx;
    }
}

void Update(int l, int r, int val)
{
    Update(l, val);
    Update(r + 1, -val);
}

long long Get(int idx)
{
    long long res = 0;

    while (idx)
    {
        res += bit[idx];
        idx -= idx & -idx;
    }

    return res;
}

void DFS(int u)
{
    in[u] = ++cnt;
    for (auto v : adj[u]) DFS(v);
    out[u] = cnt;
}

void Init()
{
    for (int i = 1; i <= n; i++) bd[i] = {1, q};
    memset(res, -1, sizeof res);
    DFS(1);
}

void Reset()
{
    for (int i = 1; i <= q; i++) group[i].clear();
    memset(bit, 0, sizeof bit);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 2; i <= n; i++)
    {
        int b; cin >> b;
        adj[b].push_back(i);
    }
    
    for (int i = 1; i <= q; i++)
    {
        int x, t;
        cin >> x >> t;
        qr[i] = {x, t};    
    }

    Init();

    for (int haha = 1; haha <= 17; haha++)
    {
        Reset();

        for (int i = 1; i <= n; i++)
        {
            if (bd[i].F > bd[i].S) continue;

            int mid = (bd[i].F + bd[i].S) / 2;
            group[mid].push_back(i);
        }

        for (int mid = 1; mid <= q; mid++)
        {
            int x = qr[mid].F;
            int t = qr[mid].S;

            Update(in[x], out[x], t);

            for (auto i : group[mid])
            {
                if (Get(in[i]) >= a[i])
                {
                    res[i] = mid;
                    bd[i].S = mid - 1;
                }
                else bd[i].F = mid + 1;
            }
        }
    }

    for (int i = 1; i <= n; i++) cout << res[i] << '\n';

    return 0;
}