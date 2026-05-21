#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define BIT(i, x) (((x) >> (i)) & 1)
#define MK(i) (1ll << (i))
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

struct Node
{
    long long val = 0;
    long long minPre, maxPre, minSuf, maxSuf;
};

struct SegmentTree
{
    vector<Node> t;
    vector<long long> lz;

    void Merge(Node a, Node b)
    {
        Node res;
        
        res.val = max(
            a.val + b.val, 
            a.val + b.val - (a.maxSuf - a.minSuf) - (b.maxPre - b.minPre) + max(a.maxSuf, b.maxPre) - min(a.minSuf, b.minPre)
        );

        res.maxPre = a.maxPre;
        res.minPre = a.minPre;
        res
    }

    void Build(int v, int l, int r, vector<int> &a)
    {
        if (l == r)
        {
            t[v].minPre = t[v].maxPre = t[v].minSuf = t[v].maxSuf = a[l];
            return;
        }

        int mid = (l + r) >> 1;
        Build(2 * v, l, mid, a);
        Build(2 * v, mid + 1, r, a);

        t[v] = Merge(t[2 * v], t[2 * v + 1]);
    }
};

int const N = 5009;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    return 0;
}