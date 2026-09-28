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
#define name "PLANET"

using ll = long long;
using ii = pair<int, int>;

template <class T> bool maxi(T &x, T const &y) { return x < y ? x = y, 1 : 0; }
template <class T> bool mini(T &x, T const &y) { return x > y ? x = y, 1 : 0; }

int const N = 2e5 + 5;
int const LOG = 20;

int n, q;
int a[N];

bool prime[N];
vector<int> facts[N];

int nxt[LOG][N], last[N];

void Sieve()
{
    memset(prime, true, sizeof prime);
    prime[0] = prime[1] = false;

    FOR(i, 2, 2e5) if (prime[i]) for (int j = i; j <= 2e5; j += i)
    {
        facts[j].push_back(i);
        prime[j] = false;
    }
}

void Build()
{
    memset(last, 0x3f, sizeof last);
    nxt[0][2 * n + 1] = 2 * n + 1;

    FORD(i, 2 * n, 1)
    {
        nxt[0][i] = nxt[0][i + 1];
        for (auto &x : facts[a[i]]) mini(nxt[0][i], last[x]), last[x] = i;
    }

    FOR(j, 1, 31 - __builtin_clz(2 * n)) FOR(i, 1, 2 * n - MK(j) + 1) if (nxt[j - 1][i] <= 2 * n)
        nxt[j][i] = nxt[j - 1][nxt[j - 1][i]];
}

int Solve(int l, int r)
{
    int i = l, res = 1;
    FORD(k, 31 - __builtin_clz(2 * n), 0) if (nxt[k][i] && nxt[k][i] <= r) i = nxt[k][i], res += MK(k);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> q;
    FOR(i, 1, n) cin >> a[i], a[i + n] = a[i];

    Sieve();
    Build();

    int res = n;
    FOR(i, 1, n) mini(res, Solve(i, i + n - 1));

    while (q--)
    {
        int l, r;
        cin >> l >> r;

        if (r < l) r += n;
        cout << (r - l + 1 == n ? res : Solve(l, r)) << '\n';
    }

    return 0;
}