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
    int cnt, ed;

    Node()
    {
        memset(child, 0, sizeof child);
        cnt = 0, ed = 0;
    }
};

struct Trie
{
    vector<Node> t;
    vector<multiset<int>> gr;
    int n, timer = 0;

    Trie(int _n = 0)
    {
        n = _n;
        timer = 0;
        t.assign(n + 5, Node());
        gr.assign(n + 5, multiset<int>());
    }

    void Add(string &s)
    {
        int u = 0;

        FOR(i, 1, sz(s))
        {
            int id = s[i - 1] - 'a';
            if (!t[u].child[id]) t[u].child[id] = ++timer;
            u = t[u].child[id];

            auto it = gr[i].find(t[u].cnt);
            if (it != gr[i].end()) gr[i].erase(it);
            gr[i].insert(++t[u].cnt);
        }

        t[u].ed++;
    }

    bool Del(string &s)
    {
        int u = 0;

        for (auto &c : s)
        {
            int id = c - 'a';
            if (!t[u].child[id]) return false;
            u = t[u].child[id];
        }

        if (!t[u].ed) return false;

        u = 0;
        FOR(i, 1, sz(s))
        {
            int id = s[i - 1] - 'a';
            u = t[u].child[id];

            auto it = gr[i].find(t[u].cnt);
            if (it != gr[i].end()) gr[i].erase(it);
            gr[i].insert(--t[u].cnt);
        }

        t[u].ed--;
        return true;
    }

    bool Query(int k, int len)
    {
        if (gr[len].empty()) return false;
        return *gr[len].rbegin() >= k;
    }
};

int const N = 1e5 + 5;

int n;
string s[N];

Trie trie;
bool mark[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    trie = Trie(N);

    FOR(i, 1, n)
    {
        int type; cin >> type;

        if (type == 1)
        {
            cin >> s[i];
            reverse(all(s[i]));
            trie.Add(s[i]);

            mark[i] = true;
        }
        else if (type == 2)
        {
            int k, l;
            cin >> k >> l;
            cout << (trie.Query(k, l) ? "YES\n" : "NO\n");
        }
        else
        {
            int id; cin >> id;
            if (mark[id]) trie.Del(s[id]), mark[id] = false;
        }
    }

    return 0;
}