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

mt19937_64 rd(time(0));
ll Rand(ll l, ll r) { return l + rd() * 1LL * rd() % (r - l + 1); }

int const lim = 950;

struct Node
{
    int child[27];
    int val = 0;

    Node()
    {
        memset(child, 0, sizeof child);
        val = 0;
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

    void Add(string &s, int val)
    {
        int u = 0;
        for (auto &c : s)
        {
            int k = c - 'a';
            if (!t[u].child[k]) t[u].child[k] = ++timer;
            u = t[u].child[k];
        }

        maxi(t[u].val, val);
    }

    int Get(string &s)
    {
        int u = 0;
        for (auto &c : s)
        {
            int k = c - 'a';
            if (!t[u].child[k]) return 0;
            u = t[u].child[k];
        }

        return t[u].val;
    }
};

struct Segment
{
    int l, r, val;
    Segment(int _l = 0, int _r = 0, int _val = 0) { l = _l, r = _r, val = _val; }
};

int n;

string s, ini;
Trie trie;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    auto startTime = chrono::high_resolution_clock::now();

    cin >> ini >> n;
    trie = Trie(30 * n);
    FOR(i, 1, n)
    {
        string str;
        int val;

        cin >> str >> val;
        for (auto &c : str) assert(('a' <= c && c <= 'z') || ('0' <= c && c <= '9'));

        trie.Add(str, val);
    }

    vector<ii> res;
    int resSum = 0;

    while (chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - startTime).count() <= lim)
    {
        s = ini;
        vector<ii> v;
        int sum = 0;

        while (true)
        {
            vector<Segment> seg;
            double lmao = 0;
            int cnt = 0;

            REP(i, sz(s))
            {
                string str = "";
                FOR(j, i, min(i + 29, sz(s) - 1))
                {
                    str += s[j];
                    int val = trie.Get(str);
                    if (val)
                    {
                        seg.push_back({i, j, val});
                        if (maxi(lmao, (double)val / (j - i + 1))) REP(hihi, max(5, ++cnt)) seg.push_back({i, j, val});
                    }
                }
            }

            if (seg.empty()) break;
            
            auto haha = seg[Rand(0, sz(seg) - 1)];
            v.push_back({haha.l, haha.r});
            sum += haha.val;

            string tmp = "";
            REP(i, sz(s)) if (i < haha.l || i > haha.r) tmp += s[i];
            s = tmp;
        }

        if (maxi(resSum, sum)) res = v;
    }

    cout << sz(res) << '\n';
    for (auto &p : res) cout << p.F << ' ' << p.S << '\n';

    return 0;
}