#include <bits/stdc++.h>

using namespace std;

int n;
int a[5] {100, 20, 10, 5, 1};

int cnt = 0;

int main()
{
    cin >> n;

    for (int i = 0; i < 5; i++)
    {
        if (n / a[i] > 0)
        {
            cnt += (n / a[i]);
            n = n % a[i];
        }
    }

    cout << cnt;

    return 0;
}