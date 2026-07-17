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

int n;
int a[N];

int res = 0;

void Update(int l, int r)
{
    FORD(i, r - 1, l) swap(a[i], a[i + 1]);
}

int Get(int l, int r, int k)
{
    int res = 0;
    FOR(i, l, r) res += a[i] == k;
    return res;
}

void Decode(int &x)
{
    x = (x + res - 1) % n + 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> a[i];

    int q; cin >> q;
    while (q--)
    {
        int type, l, r, k;
        cin >> type >> l >> r;

        Decode(l), Decode(r);
        if (l > r) swap(l, r);

        if (type == 1) Update(l, r);
        else
        {
            cin >> k; Decode(k);
            res = Get(l, r, k);
            cout << res << '\n';
        }
    }
    return 0;
}