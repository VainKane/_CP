#include <bits/stdc++.h>

using namespace std;

char chr;

int m;
int n;

int main()
{
    cin >> m >> n;
    cin >> chr;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << chr;
        }

        cout << '\n';
    }
}