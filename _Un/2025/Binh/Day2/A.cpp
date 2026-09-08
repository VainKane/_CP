#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 1e5 + 5;

int r, c;
int h, w;

int cntR[N], cntC[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> r >> c;
    cin >> h >> w;

    FOR(i, 1, r)
    {
        char ch; cin >> ch;
        cntR[i] = cntR[i - 1] + (ch == '1');
    }
    FOR(i, 1, c)
    {
        char ch; cin >> ch;
        cntC[i] = cntC[i - 1] + (ch == '1');
    }

    int x2Max = 0;
    int x2Min = N;
    long long res = 0;

    FOR(i, 1, r - h + 1) 
    {
        int x2 = cntR[i + h - 1] - cntR[i - 1];
        mini(x2Min, x2);
        maxi(x2Max, x2);
    }

    FOR(i, 1, c - w + 1)
    {
        int x1 = cntC[i + w - 1] - cntC[i - 1];
        long long delta = 1ll * w * h - 1ll * h * x1;
        int k = 2 * x1 - w;

        maxi(res, 1ll * k * x2Max + delta);
        maxi(res, 1ll * k * x2Min + delta);
    }

    cout << res;

    return 0;
}