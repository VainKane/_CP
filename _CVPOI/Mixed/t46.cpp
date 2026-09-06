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

int const N = 1e5 + 5;
int const lim = 1e6;

struct FenwickTree
{
    vector<int> bit;
    int n;

    FenwickTree(int _n = 0)
    {
        n = _n;
        bit.assign(n + 5, 0);
    }

    void Update(int idx, int val) { for (; idx <= n; idx += idx & -idx) bit[idx] += val; }

    int Search(int x)
    {
        int idx = 0, s = 0;
        FORD(i, 31 - __builtin_clz(n), 0) if ((idx | MK(i)) <= n && s + bit[idx | MK(i)] <= x)
            s += bit[idx |= MK(i)];

        return idx;
    }
};

int n;
ii a[N];

FenwickTree bitUL, bitUR;
FenwickTree bitDL, bitDR;

bool Check(int k)
{
    int haha = lim - min(bitUL.Search(k), bitUR.Search(k)) + 1;
    int huhu = min(bitDL.Search(k), bitDR.Search(k));
    return haha <= huhu;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> a[i].F >> a[i].S;

    sort(a + 1, a + n + 1);

    bitUL = bitUR = bitDL = bitDR = FenwickTree(lim);
    FOR(i, 1, n) bitUR.Update(lim - a[i].S + 1, 1), bitDR.Update(a[i].S, 1);

    int res = n;
    for (int i = 1; i <= n;)
    {
        int j = i;
        for (; j <= n && a[j].F == a[i].F; j++)
        {
            bitUL.Update(lim - a[j].S + 1, 1), bitDL.Update(a[j].S, 1);
            bitUR.Update(lim - a[j].S + 1, -1), bitDR.Update(a[j].S, -1);
        }

        i = j;

        int l = 1, r = n;
        int val = r;

        while (l <= r)
        {
            int mid = l + r >> 1;
            if (Check(mid)) val = mid, r = mid - 1;
            else l = mid + 1;
        }

        mini(res, val);
    }

    cout << res;

    return 0;
}