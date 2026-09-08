#include <bits/stdc++.h>

using namespace std;

int n;
long long sum = 0;

int main()
{
    cin >> n;

    for (long long i = 1; i <= (long long)n; i++)
    {
        sum += (i * i * i * i);
    }

    cout << sum;
}