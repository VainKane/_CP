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
        bit.assign(n + 4, 0);
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
    int type;
    double x, y1, y2;

    bool operator < (Event const other) const
    {
        if (x != other.x) return x < other.x;
        return type < other.type;
    }
};

int const N = 1e5 + 5;

int n;
Event events[3 * N];
FenwickTree bit;

vector<double> vals;

int GetId(double const &x)
{
    return lower_bound(all(vals), x) - vals.begin() + 1;
}

void Init()
{
    sort(events + 1, events + 3 * n + 1);
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
        double x1, x2, y;
        cin >> x1 >> x2 >> y;

        if (x1 > x2) swap(x1, x2);

        events[i] = {0, x1, y, y};
        events[n + i] = {2, x2, y, y};

        vals.push_back(y);
    }
    FOR(i, 1, n)
    {
        double y1, y2, x;
        cin >> y1 >> y2 >> x;

        if (y1 > y2) swap(y1, y2);

        events[2 * n + i] = {1, x, y1, y2};

        vals.push_back(y1);
        vals.push_back(y2);
    }

    Init();

    long long res = 0;
    FOR(i, 1, 3 * n)
    {
        int type = events[i].type;
        int y1 = GetId(events[i].y1);
        int y2 = GetId(events[i].y2);

        if (type == 1) res += bit.Get(y1, y2);
        else bit.Update(y1, type == 0 ? 1 : -1);
    }
    cout << res;
    
    return 0;
}