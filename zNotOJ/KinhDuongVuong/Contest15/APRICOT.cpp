#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define BIT(i, x) (((x) >> (i)) & 1)
#define MK(i) (1LL << (i))
#define all(v) v.begin(), v.end()
#define sz(v) ((int)v.size())
#define F first
#define S second

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 1e6 + 5;

int n, m;
int a[N], l[N], r[N];

void DFS(int u)
{
    if (u == 0) return;

    DFS(l[u]); DFS(r[u]);
    swap(l[u], r[u]);
}

bool Find(int u)
{
    int v = 1;
    while (true)
    {
        if (a[u] == a[v])
        {
            if (u == v) return true;
            return false;
        }
        if (a[u] < a[v])
        {
            if (!l[v]) return false;
            v = l[v];
        }
        else
        {
            if (!r[v]) return false;
            v = r[v];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    FOR(i, 1, n) cin >> a[i] >> l[i] >> r[i];

    FOR(i, 1, m)
    {
        int type, x, y;
        cin >> type;

        if (type == 1)
        {
            cin >> x >> y;
            a[x] = y;
        }
        else if (type == 2)
        {
            cin >> x;
            DFS(x);
        }
        else
        {
            cin >> x;
            cout << (Find(x) ? "YES\n" : "NO\n");
        }
    }

    return 0;
}
