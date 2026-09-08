#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define F first
#define S second
#define all(v) v.begin(), v.end()
#define name "bolivia"

struct Node
{
    long long segments;
    int minVal, preffix, suffix, len;

    Node()
    {
        segments = minVal = preffix = suffix = len = 0;
    }

    void Merge(Node A, Node B)
    {
        preffix = suffix = segments = 0;
        minVal = min(A.minVal, B.minVal);
        len = A.len + B.len;
        
        if (A.minVal == minVal)
        {
            preffix = A.preffix + ((A.preffix == A.len && minVal == B.minVal) ? B.preffix : 0);
            segments += A.segments;
        }
        if (B.minVal == minVal)
        {
            suffix = B.suffix + ((B.preffix == B.len && minVal == A.minVal) ? A.suffix : 0);
            segments += B.segments;
        }
        if (A.minVal == B.minVal) segments += 1ll * A.suffix * B.preffix;
    }
};

struct SegmentTree
{
    vector<Node> t;
    vector<int> lz;

    int n = 0;

    void Build(int v, int l, int r, vector<int> &values)
    {
        if (l == r)
        {
            t[v].len = t[v].preffix = t[v].suffix = values[r] - values[l - 1];
            t[v].segments = 1ll * t[v].len * (t[v].len + 1) / 2;
            return;
        }

        int mid = (l + r) / 2;
        Build(2 * v, l, mid, values);
        Build(2 * v + 1, mid + 1, r, values);

        t[v].Merge(t[2 * v], t[2 * v + 1]);
    }

    SegmentTree(vector<int> &values)
    {
        n = values.size() - 1;
        t.assign(4 * n + 5, Node());
        lz.assign(4 * n + 5, 0);
        Build(1, 1, n, values);
    }

    void Push(int v)
    {
        if (lz[v])
        {
            t[2 * v].minVal += lz[v];
            t[2 * v + 1].minVal += lz[v];
            lz[2 * v] += lz[v];
            lz[2 * v + 1] += lz[v];

            lz[v] = 0;
        }
    }

    void Update(int v, int l, int r, int left, int right, int val)
    {
        if (l > right || r < left) return;
        if (left <= l && right >= r)
        {
            t[v].minVal += val;
            lz[v] += val;
            return;
        }

        Push(v);

        int mid = (l + r) / 2;
        Update(2 * v, l, mid, left, right, val);
        Update(2 * v + 1, mid + 1, r, left, right, val);

        t[v].Merge(t[2 * v], t[2 * v + 1]);
    }

    void Update(int l, int r, int val)
    {
        Update(1, 1, n, l, r, val);
    }

    long long Get()
    {
        return (t[1].minVal ? 0 : t[1].segments);
    }
};

int const N = 3e5 + 5;

int n, q;
int h[N];

pair<int, int> qr[N];
vector<int> values;

void Init()
{
    FOR(i, 1, n) values.push_back(h[i]);
    FOR(i, 1, q) values.push_back(qr[i].S);
    values.push_back(0);

    sort(all(values));
    values.erase(unique(all(values)), values.end());
}

pair<int, int> GetId(int i)
{
    int j = n - i + 1;
    if (h[i] == h[j]) return {0, 0};

    int l = lower_bound(all(values), h[i]) - values.begin();
    int r = lower_bound(all(values), h[j]) - values.begin();

    if (l > r) swap(l, r);
    return {l + 1, r};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> q;
    FOR(i, 1, n) cin >> h[i];
    FOR(i, 1, q) cin >> qr[i].F >> qr[i].S;

    Init();
    SegmentTree it(values);

    FOR(i, 1, n / 2)
    {
        pair<int, int> p = GetId(i);
        if (p.F) it.Update(p.F, p.S, 1);
    }

    cout << it.Get();

    FOR(i, 1, q)
    {
        pair<int, int> p = GetId(qr[i].F);
        if (p.F) it.Update(p.F, p.S, -1);
        
        h[qr[i].F] = qr[i].S;
        p = GetId(qr[i].F);
        if (p.F) it.Update(p.F, p.S, 1);

        cout << '\n' << it.Get();
    }

    return 0;
}