#include <bits/stdc++.h>

using namespace std;

int n;

long long sum = 0;

int main()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        sum += (long long)i * i;
    }

    cout << sum;
}