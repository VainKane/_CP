#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 5;

int n, k;
int a[N];

map<int, int> visted;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); 

    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        visted[a[i]] = i;
    }

    for (int i = 1; i <= n; i++)
    {
        int exp = 2 * k - a[i];
        for (int k = 1; k <= 2; k++)
        {
            if (visted.count(exp) && visted[exp] != i)
            {
                for (int j = 1; j <= n; j++)
                {
                    if (a[j] == exp && i != j) 
                    {
                        cout << i << ' ' << j;
                        exit(0);
                    }
                }
            }
            exp++;
        }
    }

    cout << "0 0";

    return 0;
}