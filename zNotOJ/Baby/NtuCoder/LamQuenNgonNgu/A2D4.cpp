#include <bits/stdc++.h>

using namespace std;

int n;

long long sums[102];
long long value;

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> value;
            sums[j] += value; 
        }
    }

    sort(sums, sums + n);

    cout << sums[n - 1];
}