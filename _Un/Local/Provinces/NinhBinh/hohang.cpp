#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)

int t;
int cnt1[30], cnt2[30];

bool Check(string s1, string s2)
{
    memset(cnt1, 0, sizeof cnt1);
    memset(cnt2, 0, sizeof cnt2);
    
    REP(i, s1.size())
    {
        cnt1[s1[i] - 'A']++;
        cnt2[s2[i] - 'A']++;
    }

    FOR(i, 'A', 'Z') if (cnt1[i - 'A'] != cnt2[i - 'A']) return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s1 >> s2;
        cout << Check(s1, s2) << '\n';
    }

    return 0;
}