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

int const N = 2e5 + 5;
int const M = 1e7 + 5;

struct SegmentTree
{
    vector<int> t;
    int n;

    SegmentTree(int _n = 0)
    {
        n = _n;
        t.assign(4 * n, 0);
    }

    void Update(int v, int l, int r, int pos, int val)
    {
        if (l == r)
        {
            t[v] = val;
            return;
        }

        int mid = l + r >> 1;
        if (pos <= mid) Update(v << 1, l, mid, pos, val);
        else Update(v << 1 | 1, mid + 1, r, pos, val);

        t[v] = min(t[v << 1], t[v << 1 | 1]);
    }

    int Search(int v, int l, int r, int left, int right, int val)
    {
        if (t[v] >= val || l > right || r < left) return 0;
        if (l == r) return l;

        int mid = l + r >> 1;

        int pos = Search(v << 1, l, mid, left, right, val);
        if (pos) return pos;
        return Search(v << 1 | 1, mid + 1, r, left, right, val);
    }

    void Update(int pos, int val) { Update(1, 1, n, pos, val); }
    int Search(int l, int r, int val) { return Search(1, 1, n, l, r, val); }
};

int n, q;

int a[N];
vector<ii> qr[N];

bool prime[M];

int mask[M];
SegmentTree it;

vector<int> primes;
int res[N];

vector<int> facts[N];
vector<int> pos[M];

void Init()
{
    memset(prime, true, sizeof prime);
    prime[0] = prime[1] = false;

    FOR(i, 2, sqrt(1e7)) if (prime[i]) for (int j = i * i; j <= 1e7; j += i) prime[j] = false;

    FOR(i, 2, 1e7) if (prime[i])
    {
        primes.push_back(i);
        for (int j = i; j <= 1e7; j += i) if (!pos[j].empty()) for (auto &idx : pos[j])
            facts[idx].push_back(sz(primes));
    }

    it = SegmentTree(sz(primes));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    FOR(i, 1, n) cin >> a[i], pos[a[i]].push_back(i);
    FOR(i, 1, q)
    {
        int l, r;
        cin >> l >> r;
        qr[r].push_back({l, i});
    }

    Init();

    FOR(i, 1, n)
    {
        for (auto &j : facts[i]) it.Update(j, i);
        for (auto &p : qr[i]) res[p.S] = primes[it.Search(1, sz(primes), p.F) - 1];
    }

    FOR(i, 1, q) cout << res[i] << '\n';

    return 0;
}