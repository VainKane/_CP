#include <bits/stdc++.h>

using namespace std;

int n;
int m;

int a[(int)1e5 + 10];
int b[(int)1e5 + 10];

long long cnt = 0;

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }

    int i = 0;
    int j = 0;

    while (i < n && j < m)
    {
        if (a[i] < b[j])
        {
            i++;
        }
        else if (b[j] < a[i])
        {
            j++;
        }
        else
        {
            int k = 0;
            int l = 0;

            int num = a[i];

            while (a[i] == num && i < n)
            {
                k++;
                i++;
            }
            while (b[j] == num && j < m)
            {
                l++;
                j++;
            }

            cnt += ((long long)k * l);
        }
    }

    cout << cnt;
}