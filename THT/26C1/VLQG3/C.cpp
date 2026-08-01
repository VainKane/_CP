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

mt19937_64 rd(time(0));
ll Rand(ll l, ll r) { return l + rd() * 1LL * rd() % (r - l + 1); }

int const N = 509;
int const lim = 2990;

int n, m;
int c[N][N];

int x[N], resX[N];
ll sum = 0, resSum = 0;

void Flip(int i, int x[], ll &sum)
{
    x[i] ^= 1;
    int delta = x[i] ? 1 : -1;
    sum += delta * c[i][i];
    FOR(j, 1, n) if (i != j && x[j]) sum += delta * (c[i][j] + c[j][i]);
}

void Cal(int x[], ll &sum)
{
    sum = 0;
    FOR(i, 1, n) FOR(j, 1, n) sum += x[i] * x[j] * c[i][j];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    auto startTime = chrono::high_resolution_clock::now();

    cin >> n >> m;
    FOR(i, 1, m)
    {
        int x, y, val;
        cin >> x >> y >> val;
        
        x++, y++;
        c[x][y] = val;
    }

    FOR(i, 1, n) x[i] = resX[i] = Rand(0, 1);
    Cal(x, sum), Cal(resX, resSum);

    while (chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - startTime).count() <= lim)
    {
        bool opt = false;
        FOR(i, 1, n)
        {
            ll cur = sum;
            Flip(i, x, sum);

            if (sum > cur) opt = true;
            else Flip(i, x, sum);
        }

        if (maxi(resSum, sum)) FOR(i, 1, n) resX[i] = x[i];
        if (!opt) REP(haha, n / 15)
        {
            int idx = Rand(1, n);
            Flip(idx, x, sum);
        }
    }

    FOR(i, 1, n) cout << resX[i] << ' ';

    return 0;
}