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
#define name ""

using ll = long long;
using ii = pair<int, int>;

template <class T> bool maxi(T &x, T const &y) { return x < y ? x = y, 1 : 0; }
template <class T> bool mini(T &x, T const &y) { return x > y ? x = y, 1 : 0; }

int const N = MK(20) + 5;

int n, q;
int a[N];

ll t[N << 1];
int len[N << 1], lz[N << 1];

void Build(int v, int l, int r)
{
    len[v] = r - l + 1;

    if (l == r)
    {
        t[v] = a[l];
        return;
    }

    int mid = l + r >> 1;
    Build(v << 1, l, mid);
    Build(v << 1 | 1, mid + 1, r);

    t[v] = t[v << 1] + t[v << 1 | 1];
}

void Lazy(int v)
{
    if (lz[v] != -1)
    {
        FOR(u, v << 1, v << 1 | 1)
        {
            t[u] = 1LL * len[u] * lz[v];
            lz[u] = lz[v];
        }

        lz[v] = -1;
    }
}

void Update(int v, int l, int r, int left, int right, int k, int val, int i)
{
    if (l > right || r < left) return;
    if (left <= l && right >= r)
    {
        t[v] = 1LL * len[v] * val;
        lz[v] = val;
        return;
    }

    Lazy(v);
    int mid = l + r >> 1;

    bool b = BIT(i, k);
    Update((v << 1) ^b, l, mid, left, right, k, val, i - 1);
    Update((v << 1 | 1) ^b, mid + 1, r, left, right, k, val, i - 1);

    t[v] = t[v << 1] + t[v << 1 | 1];
}

ll Get(int v, int l, int r, int left, int right, int k, int i)
{
    if (l > right || r < left) return 0;
    if (left <= l && right >= r) return t[v];

    Lazy(v);
    int mid = l + r >> 1;

    bool b = BIT(i, k);
    ll val1 = Get((v << 1) ^b, l, mid, left, right, k, i - 1);
    ll val2 = Get((v << 1 | 1) ^b, mid + 1, r, left, right, k, i - 1);

    return val1 + val2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    REP(i, MK(n)) cin >> a[i];

    int type, l, r, k, val;
   
    memset(lz, -1, (N << 1) * sizeof(int));
    int ms = MK(n) - 1;
    Build(1, 0, ms);

    int q; cin >> q;
    while (q--)
    {
        cin >> type >> l >> r >> k;

        if (type == 1)
        {
            cin >> val;
            Update(1, 0, ms, l, r, k, val, n - 1);
        }
        else cout << Get(1, 0, ms, l, r, k, n - 1) << '\n';
    }

    return 0;
}