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

int const N = 5e5 + 5;

struct Node
{
    map<int, int> child;
    Node() { child.clear(); }
};

struct Trie
{
    vector<Node> t;
    vector<int> st, par;

    int n, k;
    int timer, pos;

    Trie(int _n = 0, int _k = 0)
    {
        n = _n, k = _k;
        timer = pos = 0;
        st.clear();

        t.assign(n + 5, Node());
        par.assign(n + 5, 0);
    }

    void Add(int x)
    {
        if (!st.empty() && x + st.back() == k)
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

int n, k;

Trie trie;
int id[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;

    trie = Trie(n, k);
    FOR(i, 1, n)
    {
        int x; cin >> x;
        trie.Add(x);
        id[i] = trie.pos;
    }

    int q; cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << (id[r] == id[l - 1] ? "YES\n" : "NO\n");
    }

    return 0;
}