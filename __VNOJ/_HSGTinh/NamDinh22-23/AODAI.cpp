#include <bits/stdc++.h>

using namespace std;

#define name "AODAI"

int n;
int cnt[5];

int res = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x; cin >> x;
        cnt[x]++;
    }

    res += cnt[4] + cnt[3];
    cnt[1] -= min(cnt[1], cnt[3]);
   
    res += cnt[2] / 2;
    cnt[2] %= 2;

    if (cnt[2])
    {
        res ++;
        cnt[1] -= min(cnt[1], 2);
    }

    res += cnt[1] / 4;
    cnt[1] %= 4;
    if (cnt[1]) res++;

    cout << res;

    return 0;
}
