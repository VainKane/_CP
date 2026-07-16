#include <bits/stdc++.h>

using namespace std;

long long n, k;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    
    long long res = 0;
    for (long long i = 1; i <= k; i++) res += __gcd(i, n);
    cout << res;

    return 0;
}