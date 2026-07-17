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

struct FenwickTree
{
    vector<long long> sum;
    vector<int> cnt;
    int n;

    FenwickTree(int _n = 0)
    {
        n = _n;
        cnt.assign(n + 5, 0);
        sum.assign(n + 5, 0);
    }

    void Update(int idx, int val, int delta)
    {
        while (idx <= n)
        {
            sum[idx] += delta * val;
            cnt[idx] += delta;
            idx += idx & -idx;
        }
    }

    int GetFreq(int idx)
    {
        int res = 0;

        while (idx)
        {
            res += cnt[idx];
            idx ^= idx & -idx;
        }

        return res;
    }

    long long GetPre(int idx)
    {
        long long res = 0;

        while (idx)
        {
            res += sum[idx];
            idx ^= idx & -idx;
        }

        return res;
    }
};

int const N = 1e5 + 5;
long long const oo = 1e18;

int n;
int h[N];

int haha[N], hehe[N];

FenwickTree bitL, bitR;
vector<int> vals;

int GetId(int x)
{
    return upper_bound(all(vals), x) - vals.begin();
}

void Compress()
{
    FOR(i, 1, n)
    {
        vals.push_back(haha[i] = h[i] - i);
        vals.push_back(hehe[i] = h[i] + i);
    }

    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());

    FOR(i, 1, n)
    {
        haha[i] = lower_bound(all(vals), haha[i]) - vals.begin() + 1;
        hehe[i] = lower_bound(all(vals), hehe[i]) - vals.begin() + 1;
    }

    bitL = bitR = FenwickTree(sz(vals));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> h[i];

    Compress();
    long long sL = 0, sR = 0;

    FOR(i, 1, n) 
    {
        bitR.Update(hehe[i], vals[hehe[i] - 1], 1);
        sR += vals[hehe[i] - 1];
    }

    long long res = oo;

    FOR(i, 1, n)
    {
        sR -= vals[hehe[i] - 1];
        sL += vals[haha[i] - 1];

        bitR.Update(hehe[i], vals[hehe[i] - 1], -1);
        bitL.Update(haha[i], vals[haha[i] - 1], 1);

        int l = max(i, n - i + 1);
        int r = 1e9 + N;
        int med = r;

        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (bitL.GetFreq(GetId(mid - i)) + bitR.GetFreq(GetId(mid + i)) >= (n + 1) / 2)
            {
                med = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }

        int idL = GetId(med - i);
        int cntL = bitL.GetFreq(idL);
        long long sumL = bitL.GetPre(idL);

        int idR = GetId(med + i);
        int cntR = bitR.GetFreq(idR);
        long long sumR = bitR.GetPre(idR);

        long long cost = 0;
        
        cost += 1LL * (med - i) * cntL - sumL;
        cost += sL - sumL - 1LL * (med - i) * (i - cntL);

        cost += 1LL * (med + i) * cntR - sumR;
        cost += sR - sumR - 1LL * (med + i) * (n - i - cntR);

        mini(res, cost);
    }

    cout << res;

    return 0;
}