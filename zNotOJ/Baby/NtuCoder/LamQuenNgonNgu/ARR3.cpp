#include <bits/stdc++.h>

using namespace std;

int n;

long long value;

long long res;

bool isFirst = true;

int main()
{
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        cin >> value;

        if (value % 2 == 1)
        {
            if (isFirst == true)
            {
                res = value;
                isFirst = false;
            }
            else if (value < res)
            {
                res = value;
            }
        }
    }

    cout << res;
}