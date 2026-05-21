#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define name "triprime"

bool isPrime(int x)
{
    FOR(i, 2, sqrt(x)) if (x % i == 0) return false;
    return x > 1;
}

bool Check(int n)
{
    vector<int> divs;

    FOR(i, 2, sqrt(n)) if (n % i == 0)
    {
        if (isPrime(i)) divs.push_back(i);
        if (isPrime(n / i)) divs.push_back(n / i);
    }

    for (auto x : divs) for (auto y : divs) if (n % (x * y) == 0)
    {
        int z = n / (x * y);
        if (x == y || y == z || x == z) continue;
        if (isPrime(z)) return true;
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    int n; cin >> n;
    cout << (Check(n) ? "YES" : "NO");
}