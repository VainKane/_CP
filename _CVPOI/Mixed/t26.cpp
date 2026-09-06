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

struct FenwickTree
{
    vector<int> bit;
    int n;

    FenwickTree(int _n = 0)
    {
        n = _n;
        bit.assign(n + 5, 0);
    }

    void Update(int idx, int val) { for (; idx; idx ^= idx & -idx) bit[idx] += val; }

    int Get(int idx)
    {
        int res = 0;
        for (; idx <= n; idx += idx & -idx) res += bit[idx];
        return res;
    }
};

int n, q;
FenwickTree bit1, bit2;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    bit1 = bit2 = FenwickTree(n);

    while (q--)
    {
        int type, l, r;
        cin >> type >> l >> r;

        if (type == 1) bit1.Update(l, 1), bit2.Update(r, 1);
        else cout << bit2.Get(l) - bit1.Get(r + 1) << '\n';
    }

    return 0;
}