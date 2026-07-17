#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define name "SDB"
int const N = 32000;

int n;

bool prime[N + 5];
vector<int> lst;

void Sieve()
{
    memset(prime, 1, sizeof prime);
    prime[0] = prime[1] = false;

    for (int i = 2; i * i <= N; i++)
    {
        if (!prime[i]) continue;
        for (int j = i * i; j <= N; j += i) prime[j] = false;
    }
}

void Init()
{
    Sieve();
    for (int i = 1; i <= 31627; i++)
    {
        if (prime[i]) lst.push_back(i * i);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    Init();

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x; cin >> x;
        cout << *lower_bound(all(lst), x) << ' ';
    }

    return 0;
}