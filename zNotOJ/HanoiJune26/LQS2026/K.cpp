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

int const N = 2.5e5 + 5;

struct SegmentTree
{
    vector<ii> t;
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
            t[v].F += val;
            
            if (t[v].F) t[v].S = r - l + 1;
            else if (l != r) t[v].S = t[v << 1].S + t[v << 1 | 1].S;
            else t[v].S = 0;

            return;
        }

        int mid = l + r >> 1;
        Update(v << 1, l, mid, left, right, val);
        Update(v << 1 | 1, mid + 1, r, left, right, val);

        if (t[v].F) t[v].S = r - l + 1;
        else t[v].S = t[v << 1].S + t[v << 1 | 1].S;
    }

    void Update(int l, int r, int val)
    {
        if (l > r) return;
        Update(1, 1, n, l, r, val);
    }
};

int n, k;

int a[N];
SegmentTree it;

vector<int> pos[N];
int id[N];

void Init()
{
    FOR(i, 1, n) pos[i].push_back(0);
    FOR(i, 1, n)
    {
        pos[a[i]].push_back(i);
        id[i] = sz(pos[a[i]]) - 1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    FOR(i, 1, n) cin >> a[i];

    it = SegmentTree(n);
    Init();

    ll res = 0;
    FOR(i, 1, n)
    {
        it.Update(pos[a[i]][id[i] - 1] + 1, i, 1);
        if (id[i] >= k) it.Update(pos[a[i]][id[i] - k] + 1, pos[a[i]][id[i] - k + 1], -1);
        res += i - it.t[1].S;
    }

    cout << res;

    return 0;
}