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

int const N = 36;
int const M = 1e6 + 5;

int n, m;
int cnt1[M], cnt2[M];

int pw[N];
int digit[N];

void Try(int st, int pos, int n, int cnt[], int s)
{
    if (pos > n)
    {
        cnt[s]++;
        return;
    }

    if (pos <= (n + 1) / 2) FOR(i, st == 0 && pos == 1, 9)
    {
        digit[pos] = i;
        Try(st, pos + 1, n, cnt, (s + 1LL * pw[2 * n - (st + pos)] * digit[pos]) % m);
    }
    else
    {
        digit[pos] = digit[n - pos + 1];
        Try(st, pos + 1, n, cnt, (s + 1LL * pw[2 * n - (st + pos)] * digit[pos]) % m);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;

    pw[0] = 1;
    FOR(i, 1, n) pw[i] = pw[i - 1] * 10LL % m;

    Try(0, 1, n / 2, cnt1, 0);
    Try(n / 2, 1, n / 2, cnt2, 0);

    long long res = 1LL * cnt1[0] * cnt2[0];
    FOR(r1, 1, m - 1) res += 1LL * cnt1[r1] * cnt2[m - r1];
    cout << res;

    return 0;
}