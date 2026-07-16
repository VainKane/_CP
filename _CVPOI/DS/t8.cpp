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

int const N = 2e5 + 5;
int const BASE = 256;
int const NMOD = 2;
int const MODS[] = {(int)1e9 + 2277, (int)1e9 + 5277};

int pw[NMOD][N];
int hs[3][NMOD][N];
int id[256];

struct Hash
{
    int x[NMOD];

    Hash()
    {
        memset(x, 0, sizeof x);
    }

    bool operator == (Hash const other) const
    {
        REP(k, NMOD) if (x[k] != other.x[k]) return false;
        return true;
    }
};

struct Gen
{
    int n;
    vector<Hash> t;
    vector<char> lz;
    vector<int> sz;
    string s;

    Hash Merge(Hash hsL, Hash hsR, int szL)
    {
        Hash res = hsR;
        
        REP(k, NMOD)
            res.x[k] = (1LL * res.x[k] * pw[k][szL] + hsL.x[k]) % MODS[k];
        
        return res;
    }

    void Build(int v, int l, int r)
    {
        sz[v] = r - l + 1;
        if (l == r)
        {
            REP(k, NMOD) t[v].x[k] = s[l - 1];
            return;
        }

        int mid = (l + r) >> 1;
        Build(v << 1, l, mid);
        Build(v << 1 | 1, mid + 1, r);

        t[v] = Merge(t[v << 1], t[v << 1 | 1], sz[v << 1]);
    }

    Gen(string _s = {})
    {
        s = _s;
        n = sz(s);

        t.assign(4 * n, Hash());
        lz.assign(4 * n, 0);
        sz.assign(4 * n, 0);

        if (n) Build(1, 1, n);
    }

    void Lazy(int v)
    {
        if (lz[v])
        {
            FOR(u, v << 1, v << 1 | 1)
            {
                REP(k, NMOD) t[u].x[k] = hs[id[lz[v]]][k][sz[u]];
                lz[u] = lz[v];
            }

            lz[v] = 0;
        }
    }

    void Update(int v, int l, int r, int left, int right, char val)
    {
        if (l > right || r < left) return;
        if (left <= l && right >= r)
        {
            REP(k, NMOD) t[v].x[k] = hs[id[val]][k][sz[v]];
            lz[v] = val;
            return;
        }
    
        Lazy(v);
        int mid = (l + r) >> 1;

        Update(v << 1, l, mid, left, right, val);
        Update(v << 1 | 1, mid + 1, r, left, right, val);

        t[v] = Merge(t[v << 1], t[v << 1 | 1], sz[v << 1]);
    }

    void Update(int l, int r, char val)
    {
        if (l > r) return;
        Update(1, 1, n, l, r, val);
    }

    bool operator < (Gen const other) const
    {
        REP(i, n) if (s[i] != other.s[i]) return s[i] < other.s[i];
        return false;
    }

    bool operator == (Gen const other) const
    {
        REP(i, n) if (s[i] != other.s[i]) return false;
        return true;
    }

    Gen operator + (Gen const other) const
    {
        Gen res = *this;

        REP(i, n) if (res.s[i] != other.s[i]) 
            res.s[i] = 'V' ^ 'O' ^ 'I' ^ res.s[i] ^ other.s[i];
        
        return res;
    }
};

int n;
string a, b, c, t;
vector<Gen> avail;
bool ok[67];

bool Insert(vector<Gen> &nxt)
{
    memset(ok, true, sizeof ok);
    bool hihi = false;

    REP(i, sz(nxt)) for(auto &g : avail) if (nxt[i] == g) ok[i] = false;
    REP(i, sz(nxt)) if (ok[i]) avail.push_back(nxt[i]), hihi = true;

    return hihi;
}

void Init()
{
    REP(i, 3) id["VOI"[i]] = i;

    REP(k, NMOD) 
    {
        pw[k][0] = 1;
        
        FOR(i, 1, n) 
        {
            pw[k][i] = 1LL * pw[k][i - 1] * BASE % MODS[k];
            REP(j, 3) hs[j][k][i] = (hs[j][k][i - 1] + 1LL * "VOI"[j] * pw[k][i - 1]) % MODS[k];
        }
    }

    avail = {Gen(a), Gen(b), Gen(c)};

    while (true)
    {
        vector<Gen> nxt;
        for (auto &g1 : avail) for (auto &g2 : avail) nxt.push_back(g1 + g2);
        
        sort(all(nxt));
        nxt.erase(unique(all(nxt)), nxt.end());
        if (!Insert(nxt)) break;
    }

    for (auto &g : avail) g.Build(1, 1, n);
}

bool Exist(Gen &g)
{
    for (auto &lmao : avail) if (lmao.t[1] == g.t[1]) return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    cin >> a >> b >> c;

    Init();

    int q; cin >> q;
    cin >> t;

    Gen g(t);

    cout << (Exist(g) ? "Yes\n" : "No\n");

    while (q--)
    {
        int l, r;
        char c;

        cin >> l >> r >> c;
        g.Update(l, r, c);

        cout << (Exist(g) ? "Yes\n" : "No\n");
    }

    return 0;
}