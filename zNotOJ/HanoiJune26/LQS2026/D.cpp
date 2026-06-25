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

int const N = 1e6 + 5;
int const LOG = 21;

struct Node
{
    map<int, int> child;
    Node() { child.clear(); }
};

struct Trie
{
    vector<Node> t;
    vector<int> st, par;
    
    int n;
    int pos, timer;

    Trie(int _n = 0)
    {
        n = _n;
        pos = timer = 1;

        st.clear();
        t.assign(n + 5, Node());
        par.assign(n + 5, 0);
    }

    void Add(int x)
    {
        if (!st.empty() && st.back() == x)
        {
            pos = par[pos];
            st.pop_back();
        }
        else
        {
            int &u = t[pos].child[x];
            if (!u) par[u = ++timer] = pos;
            pos = u;
            st.push_back(x);
        }
    }
};

int n, q;
Trie trie;
int node[N];

int h[N], pos[N];
int up[2 * N][25];
int timer = 0;

bool cmp(int u, int v) { return pos[u] < pos[v]; }

void DFS(int u)
{
    up[++timer][0] = u;
    pos[u] = timer;

    for (auto &p : trie.t[u].child)
    {
        h[p.S] = h[u] + 1;
        DFS(p.S);
        up[++timer][0] = u;
    }
}

void Build()
{
    DFS(1);
    FOR(j, 1, 31 - __builtin_clz(timer)) FOR(u, 1, timer - MK(j) + 1)
        up[u][j] = min(up[u][j - 1], up[u + MK(j - 1)][j - 1], cmp);
}

int LCA(int u, int v)
{
    u = pos[u], v = pos[v];
    if (u > v) swap(u, v);

    int k = 31 - __builtin_clz(v - u + 1);
    return min(up[u][k], up[v - MK(k) + 1][k], cmp);
}

int Dist(int u, int v) { return h[u] + h[v] - 2 * h[LCA(u, v)]; }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    trie = Trie(n);

    FOR(i, 1, n)
    {
        int x; cin >> x;
        trie.Add(x);
        node[i] = trie.pos;
    }

    Build();
    node[0] = 1;

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << Dist(node[r], node[l - 1]) << '\n';
    }

    return 0;
}