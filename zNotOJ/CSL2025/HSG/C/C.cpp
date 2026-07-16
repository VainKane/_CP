#include <bits/stdc++.h>

using namespace std;

bool Check(int n)
{
    if (n <= 1) return false;

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0) return false;
    }

    return true;
}

int Sum(int n)
{
    int sum = 0;

    while (n)
    {
        sum += n % 10;
        n /= 10;
    }

    return sum;
}

int t;
int l;
int r;

int p[5 * (int)1e5 + 10];
bool prime[50];

int main()
{
    cin >> t;

    for (int i = 0; i <= 54; i++)
        prime[i] = Check(i);

    p[0] = 0;
    for (int i = 1; i <= 5 * 1e5; i++) p[i] = p[i - 1] + prime[Sum(i)];

    while (t--)
    {
        cin >> l >> r;

        cout << p[r] - p[l - 1] << '\n';
    }


    return 0;
}
