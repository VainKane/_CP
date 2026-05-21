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

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

struct FenwickTree
{
    vector<int> bit;
    int n;

    FenwickTree(int _n = 0)
    {
        n = _n;
        bit.assign(n + 5, 0);
    }

    void Update(int idx, int val)
    {
        while (idx <= n)
        {
            bit[idx] += val;
            idx += idx & -idx;
        }
    }

    void Update(int l, int r, int val)
    {
        Update(l, val);
        Update(r + 1, -val);
    }

    int Get(int idx)
    {
        int res = 0;

        while (idx)
        {
            res += bit[idx];
            idx ^= idx & -idx;
        }

        return res;
    }
};

struct Event
{
    int type, x1, x2, y, id;

    bool operator < (Event const other) const
    {
        if (y != other.y) return y < other.y;
        return type < other.type;
    }
};

int const N = 2e5 + 5;

int n, p, q;

pair<int, int> op[N];
pair<int, int> qr[N];

vector<int> valsX, valsY;
FenwickTree bit;

vector<Event> events;

bool res[N];

int GetId(vector<int> &vals, int x)
{
    return lower_bound(all(vals), x) - vals.begin() + 1;
}

void Compress()
{
    FOR(i, 1, p)
    {
        valsX.push_back(op[i].S);
        valsY.push_back(op[i].S);
    }
    FOR(i, 1, q)
    {
        valsX.push_back(qr[i].F);
        valsY.push_back(qr[i].S);
    }

    sort(all(valsX));
    sort(all(valsY));

    valsX.erase(unique(all(valsX)), valsX.end());
    valsY.erase(unique(all(valsY)), valsY.end());

    bit = FenwickTree(sz(valsX));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> p;
    FOR(i, 1, p) cin >> op[i].F >> op[i].S;
    cin >> q;
    FOR(i, 1, q) cin >> qr[i].F >> qr[i].S;

    Compress();

    FOR(i, 1, p)
    {
        int x = GetId(valsX, op[i].S);
        int y = GetId(valsY, op[i].S);

        if (op[i].F == 1)
        {
            events.push_back({1, 1, x, 1, 0});
            events.push_back({3, 1, x, y, 0});
        }
        else
        {
            events.push_back({1, x, sz(valsX), y, 0});
            events.push_back({3, x, sz(valsX), sz(valsY), 0});
        }
    }

    FOR(i, 1, q)
    {
        int x = GetId(valsX, qr[i].F);
        int y = GetId(valsY, qr[i].S);
        events.push_back({2, x, x, y, i});
    }

    sort(all(events));

    for (auto &e : events)
    {
        if (e.type == 1) bit.Update(e.x1, e.x2, 1);
        else if (e.type == 3) bit.Update(e.x1, e.x2, -1);
        else res[e.id] = bit.Get(e.x1) & 1;
    }

    FOR(i, 1, q) cout << res[i] << '\n';

    return 0;
}
