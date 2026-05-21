#include <bits/stdc++.h>

using namespace std;

int Abs(int a)
{
    if (a >= 0)
    {
        return a;
    }
    else
    {
        return -1 * a;
    }
}

int n;
int k;

int heights[100005];

int streak = 0;
int res = 0;

int main()
{
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> heights[i];
    }

    sort(heights, heights + n);

    for (int i = 0; i + 1 < n; i++)
    {
        
    }

    cout << res;
}