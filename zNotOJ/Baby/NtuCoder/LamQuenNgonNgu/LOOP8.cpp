#include <bits/stdc++.h>

using namespace std;

bool Check(long long n)
{
    if (n % 2 == 0)
    {
        return false;
    }
    else if ((long long)sqrt(n) * (long long)sqrt(n) == n)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int n;
long long value;
int count1 = 0;

int main()
{
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        cin >> value;

        if (Check(value))
        {
            count1 += 1;
        }
    }

    cout << count1;
}