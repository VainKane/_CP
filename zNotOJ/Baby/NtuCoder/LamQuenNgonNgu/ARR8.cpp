#include <bits/stdc++.h>

using namespace std;

int n;

int count1[102];

int res = 0;

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        long long value;

        cin >> value;

        int count = count1[value] += 1;

        if (count > res)
        {
            res = count;
        }
    }

    cout << res;
}