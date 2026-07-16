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

struct Query
{
    int x, y;
    char dir;

    void Input()
    {
        cin >> x >> y >> dir;
    }
};

struct SegmentTree
{
    vector<int> t;
    vector<int> lz;
    int n;

    SegmentTree(int _n = 0)
    {
        n = _n;
        t.assign(4 * n, 1);
        lz.assign(4 * n, 0);
    }

    void Push(int v)
    {
        if (lz[v])
        {
            FOR(u, 2 * v, 2 * v + 1)
            {
                maxi(t[u], lz[v]);
                maxi(lz[u], lz[v]);
            }
            lz[v] = 0;
        }
    }

    void Update(int v, int l, int r, int left, int right, int val)
    {
        if (l > right || r < left) return;
        if (left <= l && right >= r)
        {
            maxi(t[v], val);
            maxi(lz[v], val);
            return;
        }

        Push(v);
        int mid = (l + r) >> 1;

        Update(2 * v, l, mid, left, right, val);
        Update(2 * v + 1, mid + 1, r, left, right, val);

        t[v] = max(t[2 * v], t[2 * v + 1]);
    }

    int Get(int v, int l, int r, int pos)
    {
        if (l == r) return t[v];

        Push(v);
        int mid = (l + r) >> 1;

        if (pos <= mid) return Get(2 * v, l, mid, pos);
        else return Get(2 * v + 1, mid + 1, r, pos);
    }

    void Update(int l, int r, int val)
    {
        if (l > r) return;
        Update(1, 1, n, l, r, val);
    }

    int Get(int pos)
    {
        if (pos < 1 || pos > n) return 0;
        return Get(1, 1, n, pos);
    }
};

int const N = 2e5 + 5; 

int n, q;
Query qr[N];

SegmentTree itC, itR;

vector<int> valsX = {0}, valsY = {0};

void Compress()
{
    FOR(i, 1, q)
    {
        valsX.push_back(qr[i].x);
        valsY.push_back(qr[i].y);
    }

    sort(all(valsX));
    sort(all(valsY));

    valsX.erase(unique(all(valsX)), valsX.end());
    valsY.erase(unique(all(valsY)), valsY.end());

    FOR(i, 1, q)
    {
        qr[i].x = lower_bound(all(valsX), qr[i].x) - valsX.begin() + 1;
        qr[i].y = lower_bound(all(valsY), qr[i].y) - valsY.begin() + 1;
    }

    itC = SegmentTree(sz(valsX));
    itR = SegmentTree(sz(valsY));
}

int Dist(int &x, int &y, vector<int> &vals)
{
    return abs(vals[x - 1] - vals[y - 1]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    FOR(i, 1, q) qr[i].Input();

    Compress();

    FOR(i, 1, q)
    {
        if (qr[i].dir == 'U')
        {
            int y = itC.Get(qr[i].x);
            itR.Update(y, qr[i].y, qr[i].x);
            itC.Update(qr[i].x, qr[i].x, qr[i].y);

            cout << Dist(y, qr[i].y, valsY) << '\n';
        }
        else
        {
            int x = itR.Get(qr[i].y);
            itC.Update(x, qr[i].x, qr[i].y);
            itR.Update(qr[i].y, qr[i].y, qr[i].x); 

            cout << Dist(x, qr[i].x, valsX) << '\n';
        }
    }

    return 0;
}