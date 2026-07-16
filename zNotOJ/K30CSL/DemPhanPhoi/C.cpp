#include <bits/stdc++.h>

using namespace std;

#define name "C"

int const N = 5e7 + 5;

int n;
string s;

long long res = 0;

int cnt[30];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); 

    // freopen(name".inp", "r", stdin);
    // freopen(name".out", "w", stdout);

    cin >> n >> s;

    for (auto ch : s)
    {
        int k = ch - 'a';
        cnt[k]++;
        res += cnt[k] - 1;
    }

    cout << res + n;

    return 0;
}