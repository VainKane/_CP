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

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 1e5 + 5;
int const M = 1e6 + 5;

int n;

int a[N];
int pre[N];

bool prime[M];

vector<int> divs[M], facts[M];
int cnt[M];

void Sieve()
{
    memset(prime, true, sizeof prime);
    prime[0] = prime[1] = false;

    FOR(i, 2, sqrt(1e6)) if (prime[i]) for (int j = i * i; j <= 1e6; j += i) prime[j] = false;
}

int Cal(int mask, int val)
{
    int p = 1;
    for (int tmp = mask; tmp; tmp ^= tmp & -tmp)
    {
        int i = __builtin_ctz(tmp);
        p *= facts[val][i];
    }

    return cnt[p];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> a[i], pre[i] = pre[i - 1] ^ a[i];

    int lim = *max_element(a + 1, a + n + 1);
    Sieve();

    FOR(i, 1, sqrt(lim)) for (int j = i * i; j <= lim; j += i)
    {
        if (prime[i]) facts[j].push_back(i);
        if (i > 1) divs[j].push_back(i);

        if (i * i == j) continue;
        if (prime[j / i]) facts[j].push_back(j / i);
        divs[j].push_back(j / i);
    }

    int res = 0;

    FOR(i, 1, n)
    {
        int tmp = 0;
        FOR(mask, 1, MK(sz(facts[a[i]])) - 1) tmp += (__builtin_parity(mask) ? 1 : -1) * Cal(mask, a[i]);
        if (tmp & 1) res ^= pre[i];
        for (auto &x : divs[a[i]]) cnt[x]++;
    }

    memset(cnt, 0, sizeof cnt);

    FORD(i, n, 1)
    {
        int tmp = 0;
        FOR(mask, 1, MK(sz(facts[a[i]])) - 1) tmp += (__builtin_parity(mask) ? 1 : -1) * Cal(mask, a[i]);
        if (tmp & 1) res ^= pre[i - 1];
        for (auto &x : divs[a[i]]) cnt[x]++;
    }

    cout << res;

    return 0;
}