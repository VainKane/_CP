#include <bits/stdc++.h>

using namespace std;

#define name "GHH"

int const N = 1e6 + 5;

int n;
long long SumDiv[N];
vector<int> res;

void Sieve()
{
    for (int i = 1; i * i <= 1e6; i++)
    {
        for (int j = i * i; j <= 1e6; j += i)
        {
            SumDiv[j] += i;
            if (i * i != j) SumDiv[j] += j / i;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    Sieve();

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x; cin >> x;
        if (2 * x <= SumDiv[x]) res.push_back(x);
    }

    cout << res.size() << '\n';
    for (auto x : res) cout << x << '\n';

    return 0;
}