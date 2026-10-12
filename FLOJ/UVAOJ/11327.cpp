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

int const N = 2e5 + 5;
int const lim = 2e5;

int GCD(int a, int b)
{
    while (true)
    {
        if (a == 0 || b == 0 || a == b) return a | b;
        if (a > b) a %= b; else b %= a;
    }
}

int phi[N];
ll pre[N];

void Init()
{
    FOR(i, 1, lim) phi[i] = i;
    FOR(i, 2, lim) if (phi[i] == i) for (int j = i; j <= lim; j += i) phi[j] -= phi[j] / i;
    
    phi[1]++;
    FOR(i, 1, lim) pre[i] = pre[i - 1] + phi[i];
}

int Kth(int x, int k)
{
    int cnt = 0;
    FOR(i, 0, x) if (GCD(x, i) == 1 && ++cnt == k) return i;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    Init();

    ll k;
    while (cin >> k)
    {
        if (!k) return 0;
        int idx = lower_bound(pre + 1, pre + lim + 1, k) - pre;
        cout << Kth(idx, k - pre[idx - 1]) << '/' << idx << '\n';
    }

    return 0;
}