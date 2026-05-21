#include <bits/stdc++.h>

using namespace std;

void DivisorsFind(int n, vector<int> &d)
{    
    n = abs(n);

    d.push_back(0);

    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            d.push_back(i);
            d.push_back(-1 * i);

            if (i * i != n)
            {
                d.push_back(n / i);
                d.push_back(-1 * (n / i));
            }
        }
    }
}

int Count(int a[], int n, int s)
{
    int res = 0;
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += a[i];

        if (sum == s)
        {
            res++;
            sum = 0;
        }

        if (i == n - 1 && sum != 0 ) return -1;
    }

    return res;
}


int n;
int a[109];

int res = 1;
int sum = 0;

vector<int> d;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }

    DivisorsFind(sum, d);

    for (int val : d)
    {
        res = max(res, Count(a, n, val));
    }

    cout << res;

    return 0;
}