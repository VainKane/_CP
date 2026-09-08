#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define BIT(i, x) (((x) >> (i)) & 1)
#define MK(i) (1ll << (i))
#define all(v) v.begin(), v.end()
#define sz(v) ((int)v.size())
#define F first
#define S second
#define name "XOREX"

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
    int type, x, l, r;
};

int const N = MK(19) + 5;

int n, q;
int a[N];

Query qr[(int)2e5 + 5];
long long pre1[N], pre2[N];

void Sub1()
{
    FOR(i, 1, q)
    {
        int l = qr[i].l;
        int r = qr[i].r;
        int x = qr[i].x;

        if (qr[i].type == 1)
        {
            REP(i, n) if (i < (i ^ x)) swap(a[i], a[i ^ x]);
        }
        else if (qr[i].type == 2)
        {
            long long res = 0;
            FOR(i, l, r) res += a[i];
            cout << res << '\n';
        }
        else
        {
            long long res = 0;
            FOR(i, l, r) res += 1ll * a[i] * (i - l + 1);
            cout << res << '\n';
        }
    }

    exit(0);
}

bool CheckSub6()
{
    FOR(i, 1, q)
    {
        if (qr[i].type == 1) continue;
        if (qr[i].l || qr[i].r != n - 1) return false;
    }
    return true;
}

void Sub6()
{
    long long sum2 = 0, sum3 = 0;
    
    REP(i, n)
    {
        sum2 += a[i];
        sum3 += 1ll * a[i] * (i + 1);
    }

    FOR(id, 1, q)
    {
        if (qr[id].type == 1)
        {
            REP(i, n)
            {
                int j = i ^ qr[id].x;
                if (i >= j) continue;

                sum3 -= 1ll * a[i] * (i + 1) + 1ll * a[j] * (j + 1);
                swap(a[i], a[j]);
                sum3 += 1ll * a[i] * (i + 1) + 1ll * a[j] * (j + 1);
            }
        }
        else if (qr[id].type == 2) cout << sum2 << '\n';
        else cout << sum3 << '\n';
    }

    exit(0);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> q;
    REP(i, n) cin >> a[i];

    FOR(i, 1, q)
    {
        cin >> qr[i].type;
        if (qr[i].type == 1) cin >> qr[i].x;
        else cin >> qr[i].l >> qr[i].r;
    }

    if (CheckSub6()) Sub6();
    else Sub1();

    return 0;
}