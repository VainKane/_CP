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

int n;
int a[N];

int id[N];
vector<pair<int, int>> p1, p2;

void Try(int st, int pos, int n, vector<pair<int, int>> &v)
{
    if (pos > n)
    {
        int x = 0, y = 0;
        FOR(i, 1, n)
        {
            if (id[i] == 1) x += a[st + i];
            if (id[i] == 2) y += a[st + i];
        }

        v.push_back({x - y, x + y});
        return;
    }

    REP(i, 3)
    {
        id[pos] = i;
        Try(st, pos + 1, n, v);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> a[i];

    int n1 = n / 2, n2 = n - n1;
    Try(0, 1, n1, p1);
    Try(n1, 1, n2, p2);

    sort(all(p1)); sort(all(p2));

    int res = 0;
    int j = sz(p2) - 1;
    
    REP(i, sz(p1))
    {
        for (; j && p1[i].F + p2[j].F > 0; j--);
        if (p1[i].F + p2[j].F == 0) maxi(res, p1[i].S + p2[j].S);
    }

    cout << res / 2;

    return 0;
}
