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
int const blockSize = sqrt(N);

struct Query
{
    int l, r, id;

    Query()
    {
        l = r = id = 0;
    }

    void Input(int &_id)
    {
        id = _id;
        cin >> l >> r;
        l--;
    }

    bool operator < (Query const other) const
    {
        if (l / blockSize != other.l / blockSize) return l < other.l;
        if ((l / blockSize) & 1) return r < other.r;
        return r > other.r;
    }
};

int n, k, q;

Query qr[N];

long long pre[N];
int preL[N], preR[N]; 

int cnt[3 * N];

int preLord[N], sufLord[N];

long long cur = 0;
long long res[N];

void Compress()
{
    vector<long long> vals = {0, k, -k};
    #define GetId(x) (lower_bound(all(vals), x) - vals.begin() + 1)

    FOR(i, 1, n)
    {
        vals.push_back(pre[i]);
        vals.push_back(pre[i] - k);
        vals.push_back(pre[i] + k);
    }

    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());

    FOR(i, 0, n + 1)
    {
        preL[i] = GetId(pre[i] - k);
        preR[i] = GetId(pre[i] + k);
        pre[i] = GetId(pre[i]);
    }
}

void UpdateSub(int op[], int id)
{
    cnt[pre[id]]--;
    cur -= cnt[op[id]];
}

void UpdateAdd(int op[], int id)
{
    cur += cnt[op[id]];
    cnt[pre[id]]++;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    
    FOR(i, 1, n)
    {
        cin >> pre[i];
        pre[i] = pre[i] == 1 ? 1 : -1;
    }
    
    FOR(i, 1, n)
    {
        int x; cin >> x;
        pre[i] *= x;
        pre[i] += pre[i - 1];
    }

    cin >> q;
    FOR(i, 1, q) qr[i].Input(i);

    Compress();
    sort(qr + 1, qr + q + 1);

    int l = 1, r = 0;

    FOR(i, 1, q)
    {
        while (r < qr[i].r) UpdateAdd(preL, ++r);
        while (r > qr[i].r) UpdateSub(preL, r--);

        while (l > qr[i].l) UpdateAdd(preR, --l);
        while (l < qr[i].l) UpdateSub(preR, l++);

        res[qr[i].id] = cur;
    }

    FOR(i, 1, q) cout << res[i] << '\n';

    return 0;
}