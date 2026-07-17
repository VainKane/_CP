#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define name "reward"

int const N = 1e6 + 5;

int n, k;
int a[N];

bool prime[N];

int cnt[N];
long long pre[N];

pair<long long, int> res;

void Sieve()
{
    memset(prime, 1, sizeof prime);
    prime[0] = prime[1] = false;
    
    for (int i = 2; i * i <= 1e6; i++)
    {
        if (!prime[i]) continue;
        for (int j = i * i; j <= 1e6; j += i) prime[j] = false;
    }
}

void Init()
{
    Sieve();

    for (int i = 1; i <= n; i++)
    {
        pre[i] = pre[i - 1] + a[i];
        cnt[i] = cnt[i - 1] + prime[i];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];

    Init();

    for (int i = k; i <= n; i++)
    {
        long long s = pre[i] - pre[i - k];
        int p = cnt[i] - cnt[i - k];

        if (s > res.F) res = {s, p};
        else if (s == res.F) res.S = max(res.S, p);
    }

    cout << res.F << ' ' << res.S;

    return 0;
}