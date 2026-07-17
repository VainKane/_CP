#include <bits/stdc++.h>

using namespace std;

int Solve(int odd, int even)
{
    if (even == 0)
    {
        if (odd > 1)
        {
            return odd - 1;
        } 
        else
        {
            return 0;
        }
    }

    if (odd == 0)
    {
        if (even == 0)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }

    return odd + 1;
}

int n;
int nums[109];

int odd;
int even;

int t;

int main()
{
    cin >> t;

    while (t--)
    {
        cin >> n;
        
        odd = 0;
        even = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];

            if (nums[i] % 2 == 0)
            {
                even++;
            }
            else
            {
                odd++;
            } 
        }

        cout << Solve(odd, even) << '\n';
    }

    return 0;
}