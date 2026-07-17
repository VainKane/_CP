#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define sz(v) ((int)v.size())

struct SegmentTree
{
    vector<int> t;
    int n;

    void Build(int v, int l, int r, vector<int> &a)
    {
        if (l == r)
        {
            t[v] = a[l];
            return;
        }

        int mid = (l + r) >> 1;
        Build(2 * v, l, mid, a);
        Build(2 * v + 1, mid + 1, r, a);

        t[v] = max(t[2 * v], t[2 * v + 1]);
    }

    SegmentTree(vector<int> vals = {0})
    {
        n = sz(vals) - 1;
        t.assign(4 * n, 0);
        if (n) Build(1, 1, n, vals);
    }

    void Update(int v, int l, int r, int pos, int val)
    {
        if (l == r)
        {
            t[v] = val;
            return;
        }

        int mid = (l + r) >> 1;
        if (pos <= mid) Update(2 * v, l, mid, pos, val);
        else Update(2 * v + 1, mid + 1, r, pos, val);

        t[v] = max(t[2 * v], t[2 * v + 1]);
    }

    int Get(int v, int l, int r, int left, int right)
    {
        if (l > right || r < left) return 0;
        if (left <= l && right >= r) return t[v];

        int mid = (l + r) >> 1;
        int m1 = Get(2 * v, l, mid, left, right);
        int m2 = Get(2 * v + 1, mid + 1, r, left, right);

        return max(m1, m2);
    }

    void Update(int pos, int val)
    {
        if (pos > n || pos < 1) return;
        Update(1, 1, n, pos, val);
    }

    int Get(int l, int r)
    {
        if (l > r) return 0;
        return Get(1, 1, n, l, r);
    }
};

int const N = 3e5 + 5;

int n, q;
char s[N];

SegmentTree it;
vector<int> id = {0};

int GetId(int i)
{
    int id = 0;
    FORD(j, 2, 1) if (s[i - j] == s[i]) id = i - j;
    return id; 
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    FOR(i, 1, n) cin >> s[i];

    FOR(i, 1, n) id.push_back(GetId(i));
    it = SegmentTree(id);

    while (q--)
    {
        int type, l, r;
        cin >> type >> l >> r;

        if (type == 1) 
        {
            swap(s[l], s[r]);
            FOR(i, l, l + 2) it.Update(i, GetId(i));
            FOR(i, r, r + 2) it.Update(i, GetId(i));
        }
        else cout << (it.Get(l, r) < l) << '\n';
    }

    return 0;
}