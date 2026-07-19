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

int const N = 1e5 + 5;
int const BK = 314;
int const GR = N / BK + 5;
int bkId[N], bkL[GR], bkR[GR];

int n;
int a[N];

queue<int> q[GR];
int cnt[GR][N];

int res = 0;

vector<int> GetVals(int id)
{
    vector<int> vals;

    while (!q[id].empty())
    {
        vals.push_back(q[id].front());
        cnt[id][q[id].front()] = 0;
        q[id].pop();
    }

    reverse(all(vals));
    return vals;
}

void Insert(vector<int> &v, int pos)
{
    FORD(i, v.size() - 2, pos) swap(v[i], v[i + 1]);
}

void Remove(vector<int> &v, int pos)
{
    vector<int> haha;
    REP(i, sz(v)) if (i != pos) haha.push_back(v[i]);
    v = haha;
}

void Build(vector<int> &vals, int id)
{
    reverse(all(vals));
    for (auto &x : vals)
    {
        q[id].push(x);
        cnt[id][x]++;
    }
}

void Init()
{
    FOR(i, 1, n)
    {
        int id = bkId[i] = (i - 1) / BK + 1;
        if (!bkL[id]) bkL[id] = i;
        bkR[id] = i;
    }

    FOR(id, 1, bkId[n])
    {
        vector<int> vals;
        FOR(i, bkL[id], bkR[id]) vals.push_back(a[i]);
        Build(vals, id);
    }
}

void Update(int l, int r)
{
    if (bkId[l] == bkId[r])
    {
        int id = bkId[l];
        vector<int> vals = GetVals(id);

        int x = vals[r - bkL[id]];
        Remove(vals, r - bkL[id]);
        vals.push_back(x);
        Insert(vals, l - bkL[id]);

        Build(vals, id);
        return;
    }

    vector<int> vals = GetVals(bkId[r]);
    int x = vals[r - bkL[bkId[r]]];
    Remove(vals, r - bkL[bkId[r]]);
    Build(vals, bkId[r]);

    vals = GetVals(bkId[l]);
    vals.push_back(x);
    Insert(vals, l - bkL[bkId[l]]);
    Build(vals, bkId[l]);

    FOR(i, bkId[l] + 1, bkId[r])
    {
        int x = q[i - 1].front();
        q[i].push(x);
        cnt[i][x]++;

        cnt[i - 1][x]--;
        q[i - 1].pop();
    }
}

int Get(int l, int r, int k)
{
    int res = 0;

    if (bkId[l] == bkId[r])
    {
        int id = bkId[l];
        vector<int> vals = GetVals(id);
        
        FOR(i, l - bkL[id], r - bkL[id]) res += vals[i] == k;
        Build(vals, id);
        return res;
    }

    FOR(i, bkId[l] + 1, bkId[r] - 1) res += cnt[i][k];
    return res + Get(l, bkR[bkId[l]], k) + Get(bkL[bkId[r]], r, k);
}

void Decode(int &x)
{
    x = (x + res - 1) % n + 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> a[i];

    Init();

    int q; cin >> q;
    while (q--)
    {
        int type, l, r, k;
        cin >> type >> l >> r;

        Decode(l), Decode(r);
        if (l > r) swap(l, r);

        if (type == 1) Update(l, r);
        else
        {
            cin >> k; Decode(k);
            res = Get(l, r, k);
            cout << res << '\n';
        }
    }

    return 0;
}