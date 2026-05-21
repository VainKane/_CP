#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)

int const N = 1e6 + 5;
int const BASE = 256;
int const MOD[] = {(int)1e9 + 2277, (int)1e9 + 5277};
int const NMOD = 2;

struct Hash
{
    int val[NMOD];

    Hash()
    {
        memset(val, 0, sizeof val);
    }

    bool operator == (const Hash other) const
    {
        REP(j, NMOD) if (val[j] != other.val[j]) return false;
        return true;
    }
};

string a, b;
int n, m;

int pw[NMOD][N], hs[NMOD][N];
Hash hsA;

void Init()
{
    REP(j, NMOD)
    {
        pw[j][0] = 1;
        FOR(i, 1, max(m, n)) pw[j][i] = (1ll * pw[j][i - 1] * BASE) % MOD[j];

        FOR(i, 1, n) hs[j][i] = (hs[j][i - 1] + 1ll * b[i] * pw[j][i]) % MOD[j];
        FOR(i, 1, m) hsA.val[j] = (hsA.val[j] + 1ll * a[i] * pw[j][i]) % MOD[j];
        hsA.val[j] = (1ll * hsA.val[j] * pw[j][max(m, n) - 1]) % MOD[j];
    }
}

Hash Get(int l, int r)
{
    Hash res;

    REP(j, NMOD)
    {
        int tmp = hs[j][r] - hs[j][l - 1];
        if (tmp < 0) tmp += MOD[j];

        res.val[j] = (1ll * tmp * pw[j][max(m, n) - l]) % MOD[j];
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> a >> b;

    m = a.size();
    n = b.size();
    a = " " + a;
    b = " " + b;

    Init();

    vector<int> res;
    FOR(i, 1, n)
    {
        if (Get(i, i + m - 1) == hsA) res.push_back(i); 
    }

    cout << res.size() << '\n';
    for (auto idx : res) cout << idx << ' ';

    return 0;
}