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

    int Get(int l, int r)
    {
        if (l > r) return 0;
        return Get(r) - Get(l - 1);
    }
};

struct Event
{
    int type, x, y1, y2;

    bool operator < (Event const other) const
    {
        if (x != other.x) return x < other.x;
        return type < other.type;
    }
};

struct Query
{
    int type, x1, y1, x2, y2;

    bool operator == (Query const other) const
    {
        if (x1 != other.x1) return false;
        if (y1 != other.y1) return false;
        if (x2 != other.x2) return false;
        if (y2 != other.y2) return false;
        return type == other.type;
    }
};

int const N = 1e5 + 5;
int n, m, q;

Query qr[N];
vector<pair<int, int>> c[3 * N], r[3 * N];

vector<int> valsC, valsR;
vector<Event> events;

FenwickTree bit;

int GetId(vector<int> &vals, int x)
{
    return lower_bound(all(vals), x) - vals.begin() + 1;
}

void Compress()
{
    FOR(i, 1, q)
    {
        if (qr[i].type == 1)
        {
            valsC.push_back(qr[i].x1);
            valsC.push_back(qr[i].x2);
            valsR.push_back(qr[i].y1);
        }
        else if (qr[i].type == 2)
        {
            valsC.push_back(qr[i].x1);
            valsR.push_back(qr[i].y1);
            valsR.push_back(qr[i].y2);
        }
    }

    sort(all(valsC)); sort(all(valsR));
    valsC.erase(unique(all(valsC)), valsC.end());
    valsR.erase(unique(all(valsR)), valsR.end());
}

void MergeSegments(int n, vector<pair<int, int>> a[])
{
    FOR(id, 1, n)
    {
        vector<pair<int, int>> tmp;
        sort(all(a[id]));

        for (int i = 0; i < sz(a[id]);)
        {
            int j = i;
            int maxR = a[id][i].S;

            for (j = i; j < sz(a[id]) && a[id][j].F <= maxR; j++) maxi(maxR, a[id][j].S);
            tmp.push_back({a[id][i].F, maxR});
            i = j;
        }

        a[id] = tmp;
    }
}

int CountDia(int i, int j)
{
    if (qr[i].x1 > qr[j].x1) swap(i, j);
    if (qr[j].x1 - qr[i].x1 != qr[j].y1 - qr[i].y1) return 0;
    if (qr[j].x1 > qr[i].x2) return 0;

    return min(qr[i].x2, qr[j].x2) - qr[j].x1 + 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> q >> q >> q >> q;
    FOR(i, 1, q)
    {
        int type, x1, y1, x2, y2;
        cin >> type >> x1 >> y1 >> x2 >> y2;
        qr[i] = {type, x1, y1, x2, y2};
    }

    Compress();

    FOR(i, 1, q) if (qr[i].type != 3)
    {
        int x1 = GetId(valsC, qr[i].x1);
        int x2 = GetId(valsC, qr[i].x2);
        int y1 = GetId(valsR, qr[i].y1);
        int y2 = GetId(valsR, qr[i].y2);

        if (qr[i].type == 1) r[y1].push_back({x1, x2});
        else c[x1].push_back({y1, y2});
    }

    MergeSegments(sz(valsR), r);
    MergeSegments(sz(valsC), c);

    long long res = 0;

    FOR(y, 1, sz(valsR)) for (auto &p : r[y])
    {
        res += valsC[p.S - 1] - valsC[p.F - 1] + 1;
        events.push_back({1, p.F, y, y});
        events.push_back({3, p.S, y, y});
    }

    FOR(x, 1, sz(valsC)) for (auto &p : c[x])
    {
        res += valsR[p.S - 1] - valsR[p.F - 1] + 1;
        events.push_back({2, x, p.F, p.S});
    }

    bit = FenwickTree(sz(valsR));
    sort(all(events));

    for (auto &e : events)
    {
        if (e.type == 1) bit.Update(e.y1, 1);
        else if (e.type == 3) bit.Update(e.y1, -1);
        else res -= bit.Get(e.y1, e.y2);
    }

    vector<pair<int, int>> v;
    vector<int> plan3;

    FOR(i, 1, q) if (qr[i].type == 3)
    {
        bool ok = true;
        for (auto &id : plan3) if (qr[i] == qr[id])
        {
            ok = false;
            break;
        }

        if (!ok) continue;

        res += qr[i].x2 - qr[i].x1 + 1;
        plan3.push_back(i);

        FOR(id, 1, sz(valsC)) for (auto &p : c[id])
        {
            int x = valsC[id - 1];
            int y1 = valsR[p.F - 1];
            int y2 = valsR[p.S - 1];

            if (x < qr[i].x1 || x > qr[i].x2) continue;
            int y = qr[i].y1 + x - qr[i].x1;

            if (y < qr[i].y1 || y > qr[i].y2) continue;
            if (y < y1 || y > y2) continue;
            v.push_back({x, y});
        }

        FOR(id, 1, sz(valsR)) for (auto &p : r[id])
        {
            int y = valsR[id - 1];
            int x1 = valsC[p.F - 1];
            int x2 = valsC[p.S - 1];

            if (y < qr[i].y1 || y > qr[i].y2) continue;
            int x = qr[i].x1 + y - qr[i].y1;

            if (x < qr[i].x1 || x > qr[i].x2) continue;
            if (x < x1 || x > x2) continue;
            v.push_back({x, y});
        }
    }

    REP(i, sz(plan3)) FOR(j, i + 1, sz(plan3) - 1) res -= CountDia(plan3[i], plan3[j]);

    sort(all(v));
    v.erase(unique(all(v)), v.end());
    cout << res - sz(v);

    return 0;
}