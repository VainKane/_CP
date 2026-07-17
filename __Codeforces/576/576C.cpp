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

int const N = 1e6 + 5;
int const BK = 1000;
int bkId[N];

struct Query
{
    int l, r, id;

    void Input(int &_id)
    {
        id = _id;
        cin >> l >> r;
    }

    bool operator < (Query const other) const
    {
        if (bkId[l] != bkId[other.l]) return l < other.l;
        if (bkId[l] & 1) return r < other.r;
        return r > other.r;
    }
};

int n;
Query qr[N];

void Init()
{
    FOR(i, 1, 1e6) bkId[i] = (i - 1) / BK + 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    Init();

    cin >> n;
    FOR(i, 1, n) qr[i].Input(i);

    sort(qr + 1, qr + n + 1);
    FOR(i, 1, n) cout << qr[i].id << ' ';

    return 0;
}