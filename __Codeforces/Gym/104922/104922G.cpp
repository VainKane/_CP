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

int n, A, B;
int a[N];

ll b[N];

bool Check1(int k)
{
    ll cnt = 0;
    FOR(i, 1, n) if (b[i] > 0)
    {
        cnt += (b[i] + (A - B) - 1) / (A - B);
        if (cnt > k) return false;
    }

    return true;
}

bool Check2(int k)
{
    ll cnt = 0;
    if (*max_element(b + 1, b + n + 1) > 0) return false;
    FOR(i, 1, n) if (b[i] < 0)
    {
        cnt += -b[i] / (B - A);
        if (cnt >= k) return true;
    }

    return false;
}

bool Check3(int k) { return *max_element(b + 1, b + n + 1) <= 0; }

bool Check(int k)
{
    FOR(i, 1, n) b[i] = a[i] - 1LL * B * k;
    if (A > B) return Check1(k);
    if (B > A) return Check2(k);
    return Check3(k);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> A >> B;
    FOR(i, 1, n) cin >> a[i], a[i]++;

    int l = 0;
    int r = max(0, *max_element(a + 1, a + n + 1));
    int res = r;

    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (Check(mid))
        {
            res = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }

    cout << res;

    return 0;
}