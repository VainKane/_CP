#include <bits/stdc++.h>

using namespace std;

int n;
long long value;

int res = 0;

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> value;
        
        if (value >= 500 && value <= 3000)
        {
            res += 1;
        }
    }

    cout << res;
}