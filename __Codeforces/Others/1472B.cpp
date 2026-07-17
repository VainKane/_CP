
#include <bits/stdc++.h>

using namespace std;

string Div(int cnt1, int cnt2)
{
    if ((cnt1 % 2 == 0 && cnt1 != 0) && (cnt2 % 2 == 1))
    {
        return "YES";
    }  
    else if (cnt1 % 2 == 0 && cnt2 % 2 == 0)
    {
        return "YES";
    }

    return "NO";
}

int t;
int n;

int nums[109];

int cnt1 = 0;
int cnt2 = 0;

int main()
{
    cin >> t;

    while (t--)
    {
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            int value;
            cin >> value;

            if (value == 1)
            {
                cnt1++;
            }
            else
            {
                cnt2++;
            }
        }

        cout << Div(cnt1, cnt2) << '\n';

        cnt1 = cnt2 = 0;
    }

    return 0;
}