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
int const BASE = 256;
int const NMOD = 2;
int const MODS[] = {(int)1e9 + 2277, (int)1e9 + 5277};

struct Hash
{
    int x[NMOD];

    Hash()
    {
        memset(x, 0, sizeof x);
    }

    bool operator == (Hash const other) const
    {
        REP(k, NMOD) if (x[k] != other.x[k]) return false;
        return true;
    }
};

int n;
string s1, s2;

int pw[NMOD][N];
int hs1[NMOD][N];
int hs2[NMOD][N];

void Init()
{
    n = sz(s1);
    s2 = s1;
    reverse(all(s2));
    
    s1 = " " + s1;
    s2 = " " + s2;

    REP(k, NMOD)
    {
        pw[k][0] = 1;
        FOR(i, 1, n)
        {
            pw[k][i] = 1LL * pw[k][i - 1] * BASE % MODS[k];
            hs1[k][i] = (hs1[k][i - 1] + 1LL * s1[i] * pw[k][i - 1]) % MODS[k];
            hs2[k][i] = (hs2[k][i - 1] + 1LL * s2[i] * pw[k][i - 1]) % MODS[k];
        }
    }
}

Hash GetHash(int l, int r, int hs[][N])
{
    Hash res;

    REP(k, NMOD)
    {
        int tmp = hs[k][r] - hs[k][l - 1];
        if (tmp < 0) tmp += MODS[k];
        res.x[k] = 1LL * tmp * pw[k][n - l] % MODS[k];
    }

    return res;
}

bool Palin(int l, int r)
{
    if (l > r) return true;
    return GetHash(l, r, hs1) == GetHash(n - r + 1, n - l + 1, hs2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> s1;

    s1 = " " + s1;
    s2 = s1;

    int cnt = 0;
    while (s1[cnt + 1] == s1[sz(s1) - 1 - cnt]) cnt++;

    if (cnt == sz(s1) - 1)
    {
        cout << "1 1";
        return 0;
    }

    s1 = "";
    FOR(i, cnt + 1, sz(s2) - 1 - cnt) s1.push_back(s2[i]);

    Init();

    FOR(i, 1, n / 2) if (Palin(2 * i + 1, n)) //AAP
    {
        if (GetHash(1, i, hs1) == GetHash(i + 1, 2 * i, hs1))
        {
            cout << i + cnt + 1 << ' ' << n + cnt;
            return 0;
        }
    }

    FOR(i, 1, n / 2) if (Palin(i + 1, n - i)) //APA
    {
        if (GetHash(1, i, hs1) == GetHash(n - i + 1, n, hs1))
        {
            cout << cnt + 1 << ' ' << i + cnt;
            return 0;
        }
    }

    FOR(i, 1, n / 2) if (Palin(1, n - 2 * i)) //PAA
    {
        if (GetHash(n - i + 1, n, hs1) == GetHash(n - 2 * i + 1, n - i, hs1))
        {
            cout << cnt + 1 << ' ' << n - i + cnt;
            return 0;
        }
    }

    cout << "-1 -1";

    return 0;
}