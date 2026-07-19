#include <bits/stdc++.h>

using namespace std;

int n;

long long sum = 0;

int main()
{
    cin >> n;

    int i = 0;

    while (sum < n)
    {
        i++;
        sum += ( 1LL * (i + 1) * i ) / 2;
    }

    if (sum > n) i--;
    cout << i;

    return 0;
}