#include <bits/stdc++.h>

using namespace std;

bool Check(long long n)
{
    if ((long long)sqrt(n) * (long long)sqrt(n) == n)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int n;
int cnt = 0;
long long value;

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> value;

        if (Check(value))
        {
            cnt++;
        }
    }

    cout << cnt;
}