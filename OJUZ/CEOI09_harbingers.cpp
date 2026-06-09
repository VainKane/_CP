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
#define name "harbingers"

using ll = long long;
using ii = pair<int, int>;

template <class t> bool maxi(t &x, t const &y) { return x < y ? x = y, 1 : 0; }
template <class t> bool mini(t &x, t const &y) { return x > y ? x = y, 1 : 0; }

int const N = 1e5 + 5;
ll const oo = 1e9 + 9;

ll Ceil(ll a, ll b)
{
    if (b < 0) a = -a, b = -b;
    return (a ^ b) < 0 ? a / b : (a + b - 1) / b;
}

struct Segment
{
    ll x, a, b;

    Segment(ll _x = 0, ll _a = 0, ll _b = 0)
    {
        x = _x, a = _a, b = _b;
    }

    bool operator < (Segment const other) const
    {
        return x < other.x;
    }

    ll Val()
    {
        return x * a + b;
    }
};

struct Op
{
    int id, m;
    Segment s;
};

struct ConvexHuTrick
{
    vector<Segment> seg;
    vector<Op> st;
    int n, m;

    ConvexHuTrick(int _n = 0)
    {
        n = _n;
        m = 0;
        seg.assign(n + 5, Segment());
    }

    void Add(ll a, ll b)
    {
        int l = 1;
        int r = m;
        int id = m + 1;

        while (l <= r)
        {
            int mid = l + r >> 1;
            if (seg[mid].Val() >= seg[mid].x * a + b)
            {
                id = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }

        if (id == 1)
        {
            st.push_back({id, m, seg[id]});
            seg[m = id] = {0, a, b};

            return;
        }

        if (a == seg[id - 1].a) return;
        
        ll x = Ceil(b - seg[id - 1].b, seg[id - 1].a - a);
        maxi(x, 0LL), mini(x, oo);
        
        st.push_back({id, m, seg[id]});
        seg[m = id] = {x, a, b};
    }

    void Roll()
    {
        seg[st.back().id] = st.back().s;
        m = st.back().m;
        st.pop_back();
    }

    long long Get(int x)
    {
        int id = upper_bound(seg.begin() + 1, seg.begin() + m + 1, Segment(x)) - seg.begin() - 1;
        return x * seg[id].a + seg[id].b;
    }
};

int n;
vector<pair<int, int>> adj[N];
int s[N], t[N], d[N];
ll dp[N];

ConvexHuTrick cht;

void DFS(int u, int p)
{
    cht.Add(-d[u], dp[u]);

    for (auto &e : adj[u])
    {
        int v = e.F;
        int w = e.S;

        if (v == p) continue;
        
        d[v] = d[u] + w;
        dp[v] = cht.Get(t[v]) + 1LL * t[v] * d[v] + s[v];
        DFS(v, u);
    }

    cht.Roll();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 2, n)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    FOR(i, 2, n) cin >> s[i] >> t[i];
    
    cht = ConvexHuTrick(n);

    DFS(1, -1);
    FOR(u, 2, n) cout << dp[u] << ' ';

    return 0;
}