#include <bits/stdc++.h>

using namespace std;

int n;
long long x;
long long value;
int cnt = 0;

int main()
{
    cin >> n >> x;

    for (int i = 0; i < n; i++)
    {
        cin >> value;

        if (value >= x)
        {
            cnt++;
        }
    }

    cout << cnt;
}