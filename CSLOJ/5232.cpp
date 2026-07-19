#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define F first
#define S second

struct SegmentTree
{
    vector<pair<int, int>> t;
    int n;

    SegmentTree(int _n = 0)
    {
        n = _n;
        t.assign(4 * n, {0, 0});
    }

    void Update(int v, int l, int r, int left, int right, int val)
    {
        if (l > right || r < left) return;
        if (left <= l && right >= r)
        {
            t[v].S += val;
           
            if (t[v].S) t[v].F = r - l + 1;
            else if (l != r) t[v].F = t[2 * v].F + t[2 * v + 1].F;
            else t[v].F = 0;

            return;
        }

        int mid = (l + r) >> 1;
        Update(2 * v, l, mid, left, right, val);
        Update(2 * v + 1, mid + 1, r, left, right, val);

        if (t[v].S) t[v].F = r - l + 1;
        else t[v].F = t[2 * v].F + t[2 * v + 1].F;
    }

    void Update(int l, int r, int val)
    {
        Update(1, 1, n, l, r, val);
    }
};

struct Event
{
    int type, x, y1, y2;

    bool operator < (Event const other) const
    {
        return x < other.x;
    }
};

int const N = 1e5 + 5;

int n;
SegmentTree it(N);
Event events[2 * N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        y1++; y2++;

        events[i] = {1, x1, y1, y2};
        events[n + i] = {-1, x2, y1, y2};
    }

    sort(events + 1, events + 2 * n + 1);

    long long res = 0;

    FOR(i, 1, 2 * n - 1)
    {
        int y1 = events[i].y1;
        int y2 = events[i].y2;
        int type = events[i].type;

        it.Update(y1, y2 - 1, type);
        res += it.t[1].F * (events[i + 1].x - events[i].x);
    }

    cout << res;

    return 0;
}