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

int const N = 1e6 + 5;

int n;

string a, b, c;

int r[N], rr[N];
bool mark[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> a >> b >> c;

    n = sz(a);
    a = " " + a, b = " " + b, c = " " + c;

    FOR(i, 1, n)
    {
        r[i] = rr[i] = 67;
        int delta = a[i] + b[i] - c[i] - '0';
        
        if (delta == 0) r[i] = rr[i] = 0;
        else if (delta == -1) r[i] = 0, rr[i] = 1;
        else if (delta == 10) r[i] = 1, rr[i] = 0;
        else if (delta == 9) r[i] = rr[i] = 1;
    }

    FOR(i, 1, n) mark[i] = r[i] != 67 && rr[i] == r[i + 1];

    ll res = 0;
    int cnt = 0;

    FOR(i, 1, n)
    {
        cnt += !r[i];
        if (!rr[i]) res += cnt;
        if (!mark[i]) cnt = 0;
    }

    cout << res;

    return 0;
}