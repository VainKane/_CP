#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, a, b) for (int i = (a), _b = (b); i >= _b; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define BIT(i, x) (((x) >> (i)) & 1)
#define MK(i) (1 << (i))
#define name "DISTINCT"

int const N = 1e6 + 5;

string s;

bool cnt[MK(26) + 5];
int makr[30];
set<int> pos;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen(name".inp", "r", stdin);
    // freopen(name".out", "w", stdout);

    cin >> s;

    int n = s.size();
    s = " " + s;

    cnt[0] = 1;

    FORD(i, n, 1)
    {
        for (auto j : pos) if (s[j] == s[i]) 
        {
            pos.erase(j);
            break;
        }
        pos.insert(i);

        int mask = 0;
        for (auto j : pos)
        {
            int x = s[j] - 'a';
            mask |= MK(x);

            cnt[mask] = true;
        }
    }

    int res = 0;
    REP(i, MK(26)) res += cnt[i];

    cout << res;

    return 0;
}