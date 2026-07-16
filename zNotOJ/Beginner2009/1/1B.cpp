#include <bits/stdc++.h>

using namespace std;

bool Check(int a[], int n, int l)
{
    for (int i = l; i < n - l + 1; i += l)
    {
        for (int j = 0; j < l; j++)
        {
            if (a[j] != a[i + j])
            {
                return false;
            }
        }
    }

    return true;
}

int n;
int a[109];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int l = 1; l < n; l++)
    {
        if (n % l == 0)
        {
            if (Check(a, n, l)) 
            {
                cout << l;
                return 0;
            }
        }
    }

    return 0;
}