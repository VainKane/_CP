#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int x = 0;
    int y = 0;
};

int const N = 1e5 + 5;
int const MOD = 1e9 + 7;

int n;
int m;

int a[N];
Node t[4 * N];
int pos[N];

void Build(int v, int l, int r)
{
    t[v].x = 1;
    t[v].y = 0;

    if (l == r) 
    {
        pos[l] = v;
        return;
    }
    
    int mid = l + (r - l) / 2;
    Build(2 * v, l, mid);
    Build(2 * v + 1, mid + 1, r);
}

void Push(int v)
{
    t[2 * v].x = (1ll * t[2 * v].x * t[v].x) % MOD;
    t[2 * v].y = (1ll * t[2 * v].y * t[v].x + t[v].y) % MOD;
    t[2 * v + 1].x = (1ll * t[2 * v + 1].x * t[v].x) % MOD;
    t[2 * v + 1].y = (1ll * t[2 * v + 1].y * t[v].x + t[v].y) % MOD;

    t[v].x = 1;
    t[v].y = 0;
}

void Update(int v, int l, int r, int left, int right, int x, int y)
{
    if (l > right || r < left) return;
    if (left <= l && right >= r)
    {
        t[v].x = (1ll * t[v].x * x) % MOD;
        t[v].y = (1ll * t[v].y * x + y) % MOD;
        return;
    }

    int mid = l + (r - l) / 2;
    Push(v);
    Update(2 * v, l, mid, left, right, x, y);
    Update(2 * v + 1, mid + 1, r, left, right, x, y);
}

int Query(int u)
{
    int v = pos[u];
    int res = a[u];

    while (v)
    {
        res = (1ll * res * t[v].x + t[v].y) % MOD;
        v /= 2;
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    Build(1, 1, n);

    cin >> m;
    while (m--)
    {
        char type;
        int u, v, d, p;
        cin >> type;

        if (type == '+')
        {
            cin >> u >> v >> d;
            Update(1, 1, n, u, v, 1, d);            
        }
        else if (type == '*')
        {
            cin >> u >> v >> d;
            Update(1, 1, n, u, v, d, 0);
        }
        else
        {
            cin >> p;
            cout << Query(p) << '\n';
        }
    }

    return 0;
}