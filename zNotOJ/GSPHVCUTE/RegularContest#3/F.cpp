#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define all(v) v.begin(), v.end()
#define name "raspored"

struct BIT
{
    vector<long long> bit;
    int n;

    BIT(int _n)
    {
        n = _n;
        bit.resize(n + 5);
    }

    void Update(int idx, int val)
    {
        while (idx <= n)
        {
            bit[idx] += val;
            idx += idx & -idx;
        }
    }

    long long Get(int idx)
    {
        long long res = 0;
        
        while (idx)
        {
            res += bit[idx];
            idx -= idx & -idx;
        }
        
        return res;
    }
};

int const N = 3e5 + 5;

int subtask;
int n, q;
int t[N], d[N];
int p[N], tQr[N], dQr[N];
int sortedD[N];

long long sumT = 0, sumD = 0;
vector<long long> values;

int GetIdx(int x)
{
    return lower_bound(all(values), x) - values.begin() + 1;
}

void Init()
{
    sort(sortedD + 1, sortedD + n + 1);
    long long tmp = 0;

    FOR(i, 1, n) 
    {
        sumT += t[i];
        tmp += sortedD[i];
        sumD += tmp;
    }

    FOR(i, 1, n) values.push_back(d[i]);
    FOR(i, 1, q) values.push_back(dQr[i]);

    sort(all(values));
    values.erase(unique(all(values)), values.end());

    cout << sumT - sumD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> subtask;
    cin >> n >> q;
    FOR(i, 1, n) cin >> t[i] >> d[i], sortedD[i] = d[i];
    FOR(i, 1, q) cin >> p[i] >> tQr[i] >> dQr[i];

    Init();

    BIT cntBIT(values.size());
    BIT sumBIT(values.size());

    FOR(i, 1, n)
    {
        int idx = GetIdx(d[i]);
        cntBIT.Update(idx, 1);
        sumBIT.Update(idx, d[i]);
    }

    FOR(i, 1, q)
    {
        int &x = d[p[i]];
        
        int idx = GetIdx(x);
        int k = cntBIT.Get(idx);

        sumD -= sumBIT.Get(idx) + 1ll * (n - k) * x;
        cntBIT.Update(idx, -1);
        sumBIT.Update(idx, -x);

        x = dQr[i];

        idx = GetIdx(x);
        k = cntBIT.Get(idx);

        sumD += sumBIT.Get(idx) + 1ll * (n - k) * x;
        cntBIT.Update(idx, 1);
        sumBIT.Update(idx, x);

        sumT += (tQr[i] - t[p[i]]);
        t[p[i]] = tQr[i];

        cout << ' ' << sumT - sumD;
    }

    return 0;
}