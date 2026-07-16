#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    if (n & 1) cout << -(n + 1) / 2;
    else cout << n / 2;

    return 0;
}