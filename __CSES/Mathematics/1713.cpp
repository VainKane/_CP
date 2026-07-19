#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

int const N = 1e6 + 5;

int cntDiv[N];

void Sieve(int l, int r)
{
    FOR(i, 1, sqrt(r)) for (int j = max(i * i, (l + i - 1) / i * i); j <= r; j += i)
    {
        cntDiv[j - l]++;
        cntDiv[j - l] += (i * i != j);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    Sieve(1, 1e6);

    int n; cin >> n;
    while (n--)
    {
        int x; cin >> x;
        cout << cntDiv[x - 1] << '\n';
    }

    return 0;
}