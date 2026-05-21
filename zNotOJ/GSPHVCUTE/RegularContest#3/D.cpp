#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define left _left
#define right _right
#define name "dimghinh"

int const N = 1e5 + 5;

int n;
long long x[4], y[4];

long long top = 2e9;
long long bot = -2e9;
long long left = -2e9;
long long right = 2e9;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n;
    FOR(i, 1, n)
    {
        REP(j, 4)
        {
            int u, v;
            cin >> u >> v;
            x[j] = u + v;
            y[j] = u - v;
        }

        top = min(top, *max_element(x, x + 4) - 1);
        bot = max(bot, *min_element(x, x + 4) + 1);
        left = max(left, *min_element(y, y + 4) + 1);
        right = min(right, *max_element(y, y + 4) - 1);
    
        if (bot > top || left > right)
        {
            cout << 0;
            return 0;
        }
    }

    // cout << top << ' ' << bot << ' ' << left << ' ' << right << '\n';

    top += 2e9;
    bot += 2e9;
    left += 2e9;
    right += 2e9;

    long long evenU = top / 2 - (bot - 1) / 2;
    long long evenV = right / 2 - (left - 1) / 2;
    long long oddU = 1ll * top - bot + 1 - evenU;
    long long oddV = 1ll * right - left + 1 - evenV;

    cout << oddU * oddV + evenU * evenV;

    return 0;
}