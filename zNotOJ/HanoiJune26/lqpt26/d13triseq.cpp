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

int const N = 20;

int n;
ll k;

int a[N];
ll f[N][N][N][N];

void GetNew(int mi1, int mi2, int ma, int x, int &nmi1, int &nmi2, int &nma)
{
    nmi1 = min(x, mi1);
    nmi2 = x <= mi1 ? mi1 : min(x, mi2);
    nma = max(x, ma);
}

void Try(int pos, int mi1, int mi2, int ma)
{
    if (f[pos][mi1][mi2][ma] || pos == n)
    {
        if (pos == n) f[pos][mi1][mi2][ma] = 1;
        return;
    }

    FOR(i, 1, n)
    {
        int nmi1, nmi2, nma;
        GetNew(mi1, mi2, ma, i, nmi1, nmi2, nma);

        if (nmi1 + nmi2 > nma)
        {
            Try(pos + 1, nmi1, nmi2, nma);
            f[pos][mi1][mi2][ma] += f[pos + 1][nmi1][nmi2][nma];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    FOR(i, 1, n) cin >> a[i];

    Try(0, n + 1, n + 1, 0);

    cout << f[0][n + 1][n + 1][0] << '\n';

    int mi1 = n + 1, mi2 = n + 1, ma = 0;
    int nmi1, nmi2, nma;

    FOR(i, 1, n) FOR(x, 1, n)
    {
        GetNew(mi1, mi2, ma, x, nmi1, nmi2, nma);

        if (!f[i][nmi1][nmi2][nma]) continue;
        if (f[i][nmi1][nmi2][nma] >= k)
        {
            mi1 = nmi1, mi2 = nmi2, ma = nma;
            cout << x << ' ';
            break;
        }
        else k -= f[i][nmi1][nmi2][nma];
    }

    mi1 = n + 1, mi2 = n + 1, ma = 0;
    ll res = 0;

    FOR(i, 1, n)
    {
        FOR(x, 1, a[i] - 1)
        {
            GetNew(mi1, mi2, ma, x, nmi1, nmi2, nma);
            res += f[i][nmi1][nmi2][nma];
        }
        GetNew(mi1, mi2, ma, a[i], mi1, mi2, ma);
    }

    cout << '\n' << res + 1;

    return 0;
}