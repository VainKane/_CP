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
#define y1 akdsjlhfklasdf

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

struct SegmentTree
{
    vector<pair<int, long long>> t;
    vector<long long> vals;
    int n;

    SegmentTree(vector<long long> _vals = {})
    {
        vals = _vals;
        n = sz(vals);
        t.assign(4 * n, {0, 0});
    }

    void Update(int v, int l, int r, int left, int right, int val)
    {
        if (l > right || r < left) return;
        if (left <= l && right >= r)
        {
            t[v].F += val;
            
            if (t[v].F) t[v].S = vals[r - 1] - vals[l - 2];
            else if (l != r) t[v].S = t[v << 1].S + t[v << 1 | 1].S;
            else t[v].S = 0;

            return;
        }
    
        int mid = (l + r) >> 1;
        Update(v << 1, l, mid, left, right, val);
        Update(v << 1 | 1, mid + 1, r, left, right, val);

        if (t[v].F) t[v].S = vals[r - 1] - vals[l - 2];
        else if (l != r) t[v].S = t[v << 1].S + t[v << 1 | 1].S;
    }

    void Update(int l, int r, int val)
    {
        if (l > r) return;
        Update(1, 1, n, l, r, val);
    }
};

struct Event
{
    int x, y1, y2, type;

    bool operator < (Event const other) const
    {
        return x < other.x;
    }
};

int const N = 1e5 + 5;

int k, n;

long long x1[N], y1[N];
long long x2[N], y2[N];
long long pY[N];

int dx[256], dy[256];

vector<Event> events;
SegmentTree it;

vector<long long> vals;

int GetId(long long x)
{
    return lower_bound(all(vals), x) - vals.begin() + 1;
}

void Compress()
{
    vals = {0, k};

    FOR(i, 1, n + 1)
    {
        vals.push_back(x1[i]);
        vals.push_back(y1[i]);
        vals.push_back(x2[i] = x1[i] + k);
        vals.push_back(y2[i] = y1[i] + k);
    }

    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());

    FOR(i, 1, n + 1)
    {
        x1[i] = GetId(x1[i]);
        y1[i] = GetId(y1[i]);
        x2[i] = GetId(x2[i]);
        y2[i] = GetId(y2[i]);
    }

    it = SegmentTree(vals);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> k >> n;

    dy['N'] = 1, dy['S'] = -1;
    dx['E'] = 1, dx['W'] = -1;

    FOR(i, 1, n)
    {
        char dir; int st;
        cin >> dir >> st;
        
        x1[i + 1] = x1[i] + dx[dir] * st;
        y1[i + 1] = y1[i] + dy[dir] * st;
    }

    Compress();

    FOR(id, 1, n)
    {
        int i = id;
        int j = id + 1;
        if (x1[i] > x1[j] || y1[i] > y1[j]) swap(i, j);

        events.push_back({x1[i], y1[i], y2[j], 1});
        events.push_back({x2[j], y1[i], y2[j], -1});
    }

    sort(all(events));

    long long res = 0;
    REP(i, sz(events) - 1)
    {
        it.Update(events[i].y1 + 1, events[i].y2, events[i].type);
        res += 1LL * it.t[1].S * (vals[events[i + 1].x - 1] - vals[events[i].x - 1]);
    }

    cout << res;

    return 0;
}