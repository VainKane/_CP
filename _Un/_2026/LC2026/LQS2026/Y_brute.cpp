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

int const N = 2e6 + 5;
int const oo = 1e9 + 9;

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

    int Get(int idx)
    {
        if (idx <= 0) return 0;

        int res = 0;
        for (; idx; idx ^= idx & -idx) res += bit[idx];
        return res;
    }
};

int n;

int a[N], l[N];
FenwickTree bit;

void Init()
{
    vector<int> st;
    a[0] = oo;
    FORD(i, 2 * n, 0)
    {
        while (!st.empty() && a[st.back()] <= a[i])
        {
            l[st.back()] = i;
            st.pop_back();
        }
        st.push_back(i);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> a[i], a[n + i] = a[i];

    Init();
    bit = FenwickTree(2 * n + 1);

    int res = 0;
    FOR(i, 1, 2 * n)
    {
        if (i > n) bit.Update(l[i - n] + 1, -1);
        bit.Update(l[i] + 1, 1);
        maxi(res, bit.Get(i - n + 1));
    }

    cout << res;

    return 0;
}