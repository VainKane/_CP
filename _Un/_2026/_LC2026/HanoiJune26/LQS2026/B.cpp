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

struct Data
{
    int p, s, c;

    void Input() { cin >> p >> s >> c; }
    bool operator < (Data const other) const { return p < other.p; }
};

int const N = 5e5 + 5;
int const M = 2509;
int const LIM = 1e4;
int const oo = 1e9 + 9;

int n, m;

ii qr[N], res[N];
Data a[M];

int id[M];
int dp[2][LIM + 5];
bool cur = 1;

void Init()
{
    double rad = oo;
    FOR(i, 1, m)
    {
        id[i] = id[i - 1];
        if (mini(rad), 1.0 * a[i].c / a[i].s) id[i] = i;
    }

    sort(qr + 1, qr + n + 1);
    sort(a + 1, a + m + 1);
}

ll Cost(int idx, int w)
{

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--)
    {
        cin >> n;
        FOR(i, 1, n) cin >> qr[i].F, qr[i].S = i;

        cin >> m;
        FOR(i, 1, m) a[i].Input();

        Init();
        int idx = cur = 1;

        memset(dp[cur], 0x3f, sizeof dp[cur]);
        dp[cur][0] = 0;

        FOR(i, 1, m)
        {
            cur ^= 1;
            memset(dp[cur], 0x3f, sizeof dp[cur]);

            int bd = min(a[i].p + LIM, a[i + 1].p - 1);
            FOR(j, a[i].p, bd)
            {
                mini(dp[cur][j - a[i].p], dp[cur][max(j - a[i].s) - a[i].p] + a[i].c);

            }

            for (; idx <= n && qr[idx].F <= bd; idx++) res[a[idx].S] = dp[a[idx].F - a[i].p];
        }

        FOR(i, 1, n) cout << res[i] << ' ';
        cout << '\n';
    }

    return 0;
}