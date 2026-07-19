#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define name "SUBSTRK"

int const N = 1e6 + 5;

int n, k;
string s;

int cnt[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> k >> s;
    n = s.size();
    s = " " + s;

    long long res = 0;
    int pre = 0;
    cnt[0] = 1;

    FOR(i, 1, n) 
    {
        pre += s[i] == '1';
        if (pre >= k) res += cnt[pre - k];      
        cnt[pre]++;
    }

    cout << res;

    return 0;
}