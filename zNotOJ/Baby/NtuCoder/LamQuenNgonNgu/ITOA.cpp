#include <bits/stdc++.h>

using namespace std;

long long Reverse(long long n)
{
    long long res = 0;

    while (n > 0)
    {
        res += n % 10;
        res *= 10;
        n /= 10;
    }

    res /= 10;

    return res;
}

bool Check(long long str[], int l, int r)
{
    while (l <= r)
    {
        if (str[l] != str[r])
        {
            return false;
        }
        else
        {
            l += 1;
            r -= 1;
        }
    }

    return true;
}

int n;

int a;
int b;

long long str[100005];

int main()
{
    cin >> n;

    for (int i = 0; i < n / 2; i++)
    {
        cin >> a >> b;
        str[i] = (long long)a + b;
    }

    for (int i = n / 2; i < n; i++)
    {
        cin >> a >> b;
        str[i] = Reverse((long long)a + b);
    }

    if (Check(str, 0, n - 1))
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}