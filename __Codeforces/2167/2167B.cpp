#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

int cnt1[30], cnt2[30];

bool Solve()
{
    FOR(i, 0, 25) if (cnt1[i] != cnt2[i]) return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int q; cin >> q;
    while (q--)
    {
        memset(cnt1, 0, sizeof cnt1);
        memset(cnt2, 0, sizeof cnt2);

        int n; cin >> n;
        FOR(i, 1, n) 
        {
            char ch; cin >> ch;
            cnt1[ch - 'a']++;
        }

        FOR(i, 1, n)
        {
            char ch; cin >> ch;
            cnt2[ch - 'a']++;
        }
        
        cout << (Solve() ? "YES\n" : "NO\n");
    }

    return 0;
}