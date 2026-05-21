#include <bits/stdc++.h>

using namespace std;

long long n, k;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    
    long long c3 = k / 3;
    long long c5 = k / 5;
    long long c15 = k / 15;

    long long res = (c3 - c15) * 3;
    res += (c5 - c15) * 5;
    res += c15 * 15;
    res += k - c3 - c5 + c15;

    cout << res;

    return 0;
}