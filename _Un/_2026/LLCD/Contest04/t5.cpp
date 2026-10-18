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
int const LOG = 20;

int n, d;
int a[N];

int up[LOG][N];
int mx[LOG][N];
ll pre[N];

void Init()
{
    FOR(i, 1, n)
    {
        up[0][i] = i - a[i];
        pre[i] = pre[i - 1] + (a[i] > 0);
        mx[0][i] = a[i] - pre[i];
    }

    FOR(j, 1, 31 - __builtin_clz(n)) FOR(i, 1, n - MK(j) + 1)
    {
        up[j][i] = min(up[j - 1][i], up[j - 1][i + MK(j - 1)]);
        mx[j][i] = max(mx[j - 1][i], mx[j - 1][i + MK(j - 1)]);
    }
}

int GetMin(int l, int r)
{
    int k = 31 - __builtin_clz(r - l + 1);
    return min(up[k][l], up[k][r - MK(k) + 1]);
}

int GetMax(int l, int r)
{
    int k = 31 - __builtin_clz(r - l + 1);
    return max(mx[k][l], mx[k][r - MK(k) + 1]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> d;
    FOR(i, 1, n) cin >> a[i];

    Init();

    ll res = 0;
    FOR(i, 1, n)
    {
        int l = i, r = n;
        int idx = l - 1;

        while (l <= r)
        {
            int mid = l + r >> 1;
            if (GetMax(i, mid) + pre[mid] <= d && GetMin(i, mid) >= i) idx = mid, l = mid + 1;
            else r = mid - 1;
        }

        res += idx - i + 1;
    }

    cout << res;

    return 0;
}