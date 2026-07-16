#include <bits/stdc++.h>

using namespace std;

#define name "reward"

int const N = 1e6 + 5;

int n, k;
int a[N];

bool Check(int x)
{
    if (x <= 1) return false;
    for (int i = 2; i * i <= x; i++) if (x % i == 0) return false;
    return true;
}

pair<long long, int> res;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".ans", "w", stdout);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++)
    {
        long long s = 0;
        int cnt = 0;
        for (int j = i; j <= min(i + k - 1, n); j++)
        {
            s += a[j];
            cnt += Check(j);
        }

        if (s > res.first) res = {s, cnt};
        else if (s == res.first) res.second = max(res.second, cnt);
    }

    cout << res.first << ' ' << res.second;

    return 0;
}