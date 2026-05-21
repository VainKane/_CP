#include <bits/stdc++.h>

using namespace std;

#define name "BONUS"
int const ntest = 1e4;

int const N = 1009;
int a[N][N];

mt19937_64 rd(time(0));

long long Rand(long long l, long long r)
{
    assert(l <= r);
    return l + rd() * 1ll * rd() % (r - l + 1);
}

void GenTest()
{
    ofstream cout(name".inp");

    int m = Rand(1, 1000);
    int n = Rand(1, 1000);
    int q = Rand(1, 100);

    int cnt = 0;

    for (int i = 1; i <= m; i++) for (int j = 1; j <= n; j++)
    {
        int type = Rand(0, 40);
        if (!type || i == 1 || j == 1) a[i][j] = ++cnt;
        else
        {
            type = Rand(0, 5);
            if (type <= 3) a[i][j] = a[i - 1][j];
            else a[i][j] = a[i][j - 1];
        }
    }

    cout << m << ' ' << n << '\n';
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++) cout << a[i][j] << ' ';
        cout << '\n';
    }

    cout << q << '\n';
    while (q--)
    {
        int x1 = Rand(1, m);
        int y1 = Rand(1, n);

        cout << x1 << ' ' << y1 << ' ' << Rand(x1, m) << ' ' << Rand(y1, n) << '\n';
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

        cout << "Test: " << i << " CORRECT!\n";
    }

    return 0;
}