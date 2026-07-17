#include <bits/stdc++.h>

using namespace std;

#define name "CHONDOI"

int const N = 1e5 + 5;

int n;
int cnt[200];
long long res = 0;

string s = "HSGPT";

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string s; cin >> s;
        cnt[s[0]]++;
    }

    for (auto c : s) res += cnt[c];
    int k = res;

    res = (1ll * res * (res - 1) * (res - 2)) / 6;

    for (auto c : s)
    {
        if (cnt[c] < 2) continue;
        res -= ((1ll * cnt[c] * (cnt[c] - 1)) / 2ll) * (k - cnt[c]);
        if (cnt[c] < 3) continue;
        res -= (1ll * cnt[c] * (cnt[c] - 1) * (cnt[c] - 2)) / 6;
    }

    cout << res;

    return 0;
}