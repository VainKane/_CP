#include <bits/stdc++.h>

using namespace std;

bool Check(int n)
{
    if (n <= 1)
    {
        return false;
    }

    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}

int n;

int main()
{
    cin >> n;

    if (Check(n) == true)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

    return 0;
}
