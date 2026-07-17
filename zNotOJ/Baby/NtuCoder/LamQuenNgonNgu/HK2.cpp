#include <bits/stdc++.h>

using namespace std;

int n;
int k;

long long value;
long long sum[(int)1e5 + 10];

int main()
{
    cin >> n;

    cin >> sum[0];

    for (int i = 1; i < n; i++)
    {
        cin >> value;
        sum[i] = sum[i - 1] + value;
    }

    cin >> k;

    cout << sum[k - 1];
}