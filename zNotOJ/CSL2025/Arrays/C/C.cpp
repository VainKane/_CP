#include <bits/stdc++.h>

using namespace std;

int n;
int x;
long long pre = 0;
int nums[(int)1e5 + 10];
int value;
int cnt = 0;

map<long long, int> visisted;

int main()
{
    cin >> n >> x;

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    visisted[0] = 1;

    for (int i = 0; i < n; i++)
    {
        pre += (long long)nums[i];

        if (visisted[pre - x] > 0)
        {
            cnt += visisted[pre - x];
        }

        visisted[pre]++;
    }


    cout << cnt;

    return 0;
}
