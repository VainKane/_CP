#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define all(v) v.begin(), v.end()
#define sz(v) ((int)v.size())

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

int n;
vector<Event> events;
FenwickTree bit;

vector<int> vals;

int GetId(int x)
{
    return lower_bound(all(vals), x) - vals.begin() + 1;
}

void Init()
{
    sort(all(events));
    sort(all(vals));
    
    vals.erase(unique(all(vals)), vals.end());
    bit = FenwickTree(sz(vals));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        if (x1 > x2) swap(x1, x2);
        if (y1 > y2) swap(y1, y2);
        
        if (x1 == x2)
        {
            events.push_back({1, x1, y1, y2});
            vals.push_back(y1);
            vals.push_back(y2);
        }
        else
        {
            events.push_back({0, x1, y1, y1});
            events.push_back({2, x2, y1, y1});
            vals.push_back(y1);
        }
    }

    Init();

    long long res = 0;
    
    for (auto &e : events)
    {
        int y1 = GetId(e.y1);
        int y2 = GetId(e.y2);

        if (e.type == 1) res += bit.Get(y1, y2);
        else bit.Update(y1, !e.type ? 1 : -1);
    }
    
    cout << res;

    return 0;
}