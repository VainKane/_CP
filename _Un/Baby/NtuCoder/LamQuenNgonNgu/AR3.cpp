#include <bits/stdc++.h>

using namespace std;

int n;
long long value;
int cnt = 0;

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> value;

        if (value % 3 == 0)
        {
            cnt++;
        }
    }

    cout << cnt;
}