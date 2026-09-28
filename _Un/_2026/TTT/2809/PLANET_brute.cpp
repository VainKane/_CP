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
#define name "PLANET"

using ll = long long;
using ii = pair<int, int>;

template <class T> bool maxi(T &x, T const &y) { return x < y ? x = y, 1 : 0; }
template <class T> bool mini(T &x, T const &y) { return x > y ? x = y, 1 : 0; }

int const N = 2e5 + 5;
int const oo = 1e9 + 9;

struct SegmentTree
{
    vector<int> t;
    int n;

    void Build(int v, int l, int r, int a[])
    {
        if (l == r)
        {
            t[v] = a[l];
            return;
        }

        int mid = l + r >> 1;
        Build(v << 1, l, mid, a);
        Build(v << 1 | 1, mid + 1, r, a);

        t[v] = max(t[v << 1], t[v << 1 | 1]);
    }

    SegmentTree(int _n = 0)
    {
        n = _n;
        t.assign(4 * n, 0);
    }

    int Search(int v, int l, int r, int &left, int &right, int &val)
    {
        if (l > right || r < left || t[v] < val) return oo;
        if (l == r) return l;

        int mid = l + r >> 1;

        int pos = Search(v << 1, l, mid, left, right, val);
        if (pos != oo) return pos;
        return Search(v << 1 | 1, mid + 1, r, left, right, val);
    }

    int Search(int l, int r, int val)
    {
        if (l > r) return oo;
        return Search(1, 1, n, l, r, val);
    }
};

int n, q;
int a[N];

vector<int> facts[N];
int last[N], pre[N];

SegmentTree it;
bool prime[N];

void Sieve()
{
    memset(prime, true, sizeof prime);
    prime[0] = prime[1] = false;

    FOR(i, 2, 1e5) if (prime[i]) for (int j = i; j <= 1e5; j += i)
    {
        facts[j].push_back(i);
        prime[j] = false;
    }

    FOR(i, 1, 2 * n) for (auto &x : facts[a[i]]) maxi(pre[i], last[x]), last[x] = i;
}

int Solve(int l, int r)
{
    int res = 0, idx = l;
    while (idx <= r)
    {
        idx = it.Search(idx, r, idx);
        res++;
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen(name".inp", "r", stdin);
    // freopen(name".out", "w", stdout);

    cin >> n >> q;
    FOR(i, 1, n) cin >> a[i], a[i + n] = a[i];

    Sieve();
    it = SegmentTree(2 * n);
    it.Build(1, 1, 2 * n, pre);

    int res = n;
    FOR(i, 1, n) mini(res, Solve(i, i + n - 1));

    while (q--)
    {
        int l, r;
        cin >> l >> r;

        if (r < l) r += n;
        cout << (r - l + 1 == n ? res : Solve(l, r)) << '\n';
    }

    return 0;
}