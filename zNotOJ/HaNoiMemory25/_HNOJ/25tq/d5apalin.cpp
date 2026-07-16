#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)

int const N = 2e5 + 9;

int n;
char s[N];

void Change(int i, char ch1, char ch2, char ch3, char ch4)
{
    REP(j, 26)
    {
        char ch = j + 'a';
        if (ch == ch1 || ch == ch2 || ch == ch3 || ch == ch4) continue;
        s[i] = ch;
        break;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> s[i];

    int cnt = 0;
    FOR(i, 2, n) 
    {
        if (s[i] == s[i - 1])
        {
            Change(i, s[i - 1], s[i - 2], s[i + 1], s[i + 2]);
            cnt++;
        }
        if (s[i] == s[i - 2])
        {
            Change(i, s[i - 1], s[i - 2], s[i + 1], s[i + 2]);
            cnt++;
        }
    }

    cout << cnt << '\n';
    FOR(i, 1, n) cout << s[i];

    return 0;
}