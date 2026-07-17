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
#define name "WSHARE"

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

struct Query
{
    char type;
    int u, v;
};

int const N = 2 * 120009;
int const oo = 998244353;

int n, k;
Query qr[N];

namespace Sub1
{
    bitset<5009> bs[5009];

    bool CheckSub()
    {
        return n <= 5000;
    }

    void Process()
    {
        FOR(i, 1, n) bs[i][i] = 1;

        FOR(i, 1, n - 1 + k)
        {
            if (qr[i].type == 'S')
            {
                bs[qr[i].u] |= bs[qr[i].v];
                bs[qr[i].v] |= bs[qr[i].u];
            }
            else if (qr[i].type == 'Q') cout << (bs[qr[i].u][qr[i].v] ? "yes\n" : "no\n");
            else
            {
                int res = 0;
                FOR(u, 1, n) res += bs[u][qr[i].u];
                cout << res << '\n';
            }
        }
    }
}

namespace Sub2
{
    int timer[N];
    int cnt = 1;

    bool CheckSub()
    {
        FOR(i, 1, n - 1 + k) if (qr[i].type == 'S')
        {
            if (qr[i].u != 1 && qr[i].v != 1) return false;
        }
        return true;
    }

    bool Solve(int u, int v)
    {
        if (u == v) return true;
        if (u == 1) return timer[v] < oo;
        if (v == 1) return timer[u] < oo;
        return timer[v] <= timer[u] && timer[u] < oo;
    }

    int Solve(int u)
    {
        if (u == 1) return cnt;
        if (timer[u] < oo) return cnt - timer[u] + 2;
        return 1;
    }

    void Process()
    {
        memset(timer, 0x3f, sizeof timer);
        timer[1] = 1;

        FOR(i, 1, n - 1 + k)
        {
            int u = qr[i].u;
            int v = qr[i].v;

            if (qr[i].type == 'S')
            {
                cnt++;
                if (u != 1) timer[u] = cnt;
                if (v != 1) timer[v] = cnt;
            }
            else if (qr[i].type == 'Q') cout << (Solve(u, v) ? "yes\n" : "no\n");
            else cout << Solve(u) << '\n';
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    FOR(i, 1, n - 1 + k)
    {
        cin >> qr[i].type;
        if (qr[i].type == 'C') cin >> qr[i].u;
        else cin >> qr[i].u >> qr[i].v;
    }

    if (Sub1::CheckSub()) return Sub1::Process(), 0;
    if (Sub2::CheckSub()) return Sub2::Process(), 0;

    return 0;
}