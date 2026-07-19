#include <bits/stdc++.h>

using namespace std;

#define name "easy"

long long k;
string s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);
    
    cin >> k;
    while (cin >> s)
    {
        if (s.size() <= k) cout << s << ' ';
        else cout << s[0] << s.size() - 2 << s[s.size() - 1] << ' ';
    }

    return 0;
}