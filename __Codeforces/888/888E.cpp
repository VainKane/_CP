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

int n, m;

int a[N];
vector<int> r1, r2;

void Add(int &x, int const &y)
{
    x += y;
    if (x >= m) x -= m;
}

void Build(int st, int n, vector<int> &r)
{
    REP(mask, MK(n))
    {
        int s = 0;
        for (int tmp = mask; tmp; tmp ^= tmp & -tmp)
        {
            int i = __builtin_ctz(tmp);
            Add(s, a[st + i]);
        }

        r.push_back(s);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    REP(i, n) cin >> a[i], a[i] %= m;

    int n1 = n / 2, n2 = n - n1;
    Build(0, n1, r1);
    Build(n1, n2, r2);

    sort(all(r1)); sort(all(r2));

    int res = 0;
    int ma = 0;

    int j = sz(r2) - 1;
    REP(i, sz(r1))
    {
        for (; j && r1[i] + r2[j] >= m; j--) maxi(ma, r2[j]);
        if (r1[i] + r2[j] < m) maxi(res, r1[i] + r2[j]);
        maxi(res, (r1[i] + ma) % m);
    }

    cout << res;

    return 0;
}