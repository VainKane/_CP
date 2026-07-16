#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define all(v) v.begin(), v.end()

int const N = 1e3 + 5;

int n;
string s;

int cnt[30];

bool Check(int c, int rem)
{
    REP(i, 26) if (cnt[i] > (rem + 1) / 2) return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> s;
    n = s.size();

    REP(i, s.size()) if (++cnt[s[i] - 'A'] > (n + 1) / 2)
    {
        cout << -1;
        return 0;
    }

    REP(i, n) REP(c, 26) if (cnt[c] && c != s[i - 1] - 'A')
    {
        cnt[c]--;
        if (Check(c, n - i - 1))
        {
            s[i] = c + 'A';
            break;
        }
        cnt[c]++;
    }

    cout << s;

    return 0;
}