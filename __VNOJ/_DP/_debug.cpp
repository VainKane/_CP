#include <bits/stdc++.h>

using namespace std;

#define name "U"
int const ntest = 1e4;

mt19937_64 rd(time(0));

long long Rand(long long l, long long r)
{
    return l + rd() * 1ll * rd() % (r - l + 1);
}

void GenTest()
{
    ofstream cout(name".inp");

    int n = Rand(1, 7);
    int oo = 1e9;

    cout << n << '\n';
    int a[n + 1][n + 1];
    for (int i = 1; i <= n; i++)
    {
        a[i][i] = 0;
        for (int j = i + 1; j <= n; j++) a[i][j] = a[j][i] = Rand(-oo, oo);
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++) cout << a[i][j] << ' ';
        cout << '\n';
    }
}

int main()
{
    for (int i = 1; i <= ntest; i++)
    {
        GenTest();
        system(name".exe <"name".inp> "name".out");
        system(name"_trau.exe <"name".inp> "name".ans");

        if (system("fc "name".out "name".ans") != 0)
        {
            cout << "Test: " << i << " WRONG!\n";
            return 0;
        }

        cout << "Test: " << i << " COREECT!\n";
    }

    return 0;
}