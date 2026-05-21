#include <bits/stdc++.h>

using namespace std;

int n;
long long sum = 0;

int nums[302][302];



int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> nums[i][j];
        }
    }


    int left = (n / 2) - 1;
    int length;

    if (n % 2 == 0)
    {
        length = 2;
    }
    else
    {
        cout << nums[left + 1][left + 1] << ' ';
        length = 3;
    }

    while (length <= n)
    {
        for (int i = left; i < left + length; i++)
        {
            sum += (nums[i][left] + nums[i][left + length - 1]);
        }

        for (int i = left + 1; i < left + length - 1; i++)
        {
            sum += (nums[left][i] + nums[left + length - 1][i]);
        }


        cout << sum << ' ';
        sum = 0;
        length += 2;
        left -= 1;
    }
}