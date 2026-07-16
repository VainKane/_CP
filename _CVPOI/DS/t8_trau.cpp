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
#define name "t8"

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 2e5 + 5;

struct Gen
{
    int n;
    vector<char> s;

    Gen(int _n = 0)
    {
        n = _n;
        s.assign(n + 5, '?');
    }

    void Input()
    {
        FOR(i, 1, n) cin >> s[i];
    }

    void Print()
    {
        FOR(i, 1, n) cout << s[i];
        cout << '\n';
    }

    bool operator < (Gen const other) const
    {
        FOR(i, 1, n) if (s[i] != other.s[i]) return s[i] < other.s[i];
        return false;
    }

    bool operator == (Gen const other) const
    {
        FOR(i, 1, n) if (s[i] != other.s[i]) return false;
        return true;
    }

    Gen operator + (Gen const other) const
    {
        Gen res(n);
        FOR(i, 1, n)
        {
            if (s[i] == other.s[i]) res.s[i] = s[i];
            else res.s[i] = 'V' ^ 'O' ^ 'I' ^ s[i] ^ other.s[i];
        }
        return res;
    }
};

int n;

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
    while (true)
    {
        vector<Gen> nxt;
        for (auto &g1 : avail) for (auto &g2 : avail) nxt.push_back(g1 + g2);
        
        sort(all(nxt));
        nxt.erase(unique(all(nxt)), nxt.end());
        if (!Insert(nxt)) break;
    }
}

bool Exist(Gen g)
{
    for (auto &lmao : avail) if (lmao == g) return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen(name".inp", "r", stdin);
    // freopen(name".out", "w", stdout);

    cin >> n;
    FOR(i, 1, 3)
    {
        Gen g(n);
        g.Input();
        avail.push_back(g);
    }

    Init();

    int q; cin >> q;
    Gen g(n);
    g.Input();

    cout << (Exist(g) ? "Yes\n" : "No\n");

    while (q--)
    {
        int l, r;
        char c;

        cin >> l >> r >> c;
        FOR(i, l, r) g.s[i] = c;

        cout << (Exist(g) ? "Yes\n" : "No\n");
    }

    return 0;
}