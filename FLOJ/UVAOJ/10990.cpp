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
int const lim = 2e6;

int phi[N];
ll pre[N];

void Init()
{
    FOR(i, 1, lim) phi[i] = i;
    FOR(i, 2, lim) if (phi[i] == i) for (int j = i; j <= lim; j += i) phi[j] -= phi[j] / i;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    Init();
    FOR(i, 2, lim) pre[i] = pre[i - 1] + pre[phi[i]] - pre[phi[i] - 1] + 1;

    int q, l, r; cin >> q;
    while (q--)
    {
        cin >> l >> r;
        cout << pre[r] - pre[l - 1] << '\n';
    }

    return 0;
}