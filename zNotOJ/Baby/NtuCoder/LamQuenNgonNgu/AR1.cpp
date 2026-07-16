#include <bits/stdc++.h>

using namespace std;

int n;
long long value;
long long sum = 0;

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> value;

        sum += value;
    }

    cout << sum;
}