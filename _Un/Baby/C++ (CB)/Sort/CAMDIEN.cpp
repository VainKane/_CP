#include <bits/stdc++.h>

using namespace std;

bool cmp(int a, int b)
{
    if (a > b)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int m;
int n;

int result = 0;
int sum = -1;

int cap[100009];
long long s[100009];

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> cap[i];
    }

    sort(cap, cap + n, cmp);


    s[0] = cap[0];

    for (int i = 1; i < n; i++)
    {
        s[i] = (long long)s[i - 1] + cap[i];
    }

    int count = 0;
    int i = 0;

    while (sum < m)
    {
        sum = (s[i] - i);
        count += 1;
        i++;

        if (i == n)
        {
            break;
        }
    }

    if (count > n || sum < m)
    {
        count = -1;
    }
    
    cout << count;
}