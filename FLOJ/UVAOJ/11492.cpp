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

struct Node
{
    int child[26];
    int id;

    Node()
    {
        memset(child, 0, sizeof child);
        id = 0;
    }
};

struct Trie
{
    vector<Node> t;
    int n, timer = 0, haha = 0;

    Trie(int _n = 0)
    {
        n = _n;
        timer = haha = 0;
        t.assign(n + 5, Node());
    }

    int Add(string &s)
    {
        int u = 0;
        for (auto &c : s)
        {
            int id = c - 'a';
            if (!t[u].child[id]) t[u].child[id] = ++timer;
            u = t[u].child[id];
        }

        return t[u].id = (t[u].id ? t[u].id : ++haha);
    }
};

struct Edge
{
    int v, c, w;
};

struct State
{
    int u, c, du;

    bool operator < (State const other) const
    {
        return du > other.du;
    }
};

int const N = 4009;
int const oo = 1e9 + 9;

int n, m, s, t;
vector<Edge> adj[N];

int d[N][36];

void Dijkstra()
{
    memset(d, 0x3f, sizeof d);
    d[s][26] = 0;

    priority_queue<State> pq;
    pq.push({s, 26, d[s][26]});

    while (!pq.empty())
    {
        int u = pq.top().u;
        int c = pq.top().c;
        int du = pq.top().du;
        pq.pop();

        if (du > d[u][c]) continue;

        for (auto &e : adj[u])
        {
            int v = e.v;
            int ch = e.c;
            int w = e.w;

            if (ch != c && mini(d[v][ch], du + w)) pq.push({v, ch, d[v][ch]});
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    while (cin >> m)
    {
        if (!m) return 0;
        Trie trie(100 * m);

        string ss, st;
        cin >> ss >> st;
        s = trie.Add(ss), t = trie.Add(st);

        FOR(u, 1, 2 * m) adj[u].clear();
        FOR(i, 1, m)
        {
            string su, sv, sw;
            cin >> su >> sv >> sw;

            int u = trie.Add(su), v = trie.Add(sv);
            adj[u].push_back({v, sw[0] - 'a', sz(sw)});
            adj[v].push_back({u, sw[0] - 'a', sz(sw)});
        }

        Dijkstra();
        int res = *min_element(d[t], d[t] + 26);
        if (res < oo) cout << res << '\n';
        else cout << "impossivel\n";
    }

    return 0;
}