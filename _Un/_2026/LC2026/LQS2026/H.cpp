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

ll sum[67][2];
struct Node
{
    int child[2];
    int cnt = 0;

    Node()
    {
        child[0] = child[1] = 0;
        cnt = 0;
    }
};

struct Trie
{
    vector<Node> t;
    int n, timer = 0;

    Trie(int _n = 0)
    {
        n = _n;
        t.assign(n + 5, Node());
        timer = 0;
    }

    void Update(ll &x, int delta, Trie &other)
    {
        int u = 0, v = 0;
        bool ok = true;

        FORD(i, 59, 0)
        {
            bool k = BIT(i, x);
            u = t[u].child[k] ? t[u].child[k] : t[u].child[k] = ++timer;
            t[u].cnt += delta;

            if (!ok) continue;

            sum[i][k ^ (delta == -1)] += delta * other.t[other.t[v].child[!k]].cnt;
            if (!other.t[v].child[k]) ok = false;
            v = other.t[v].child[k];
        }
    }
};

int n;

ll a[N];
Trie tl, tr;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> a[i];

    tl = tr = Trie(60 * n);
    FOR(i, 3, n) tr.Update(a[i], 1, tl);
    tl.Update(a[1], 1, tr);

    ll res = 0;
    FOR(i, 2, n - 1)
    {
        REP(j, 60) res += sum[j][BIT(j, a[i])];
        tr.Update(a[i + 1], -1, tl);
        tl.Update(a[i], 1, tr);
    }

    cout << res;

    return 0;
}