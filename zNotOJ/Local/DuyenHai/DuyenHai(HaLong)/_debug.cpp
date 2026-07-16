#include <bits/stdc++.h>

using namespace std;

#define name "JEWELRY"
int const ntest = 1e4;

mt19937_64 rd(time(0));

long long Rand(long long l, long long r)
{
    return l + rd() * 1ll * rd() % (r - l + 1);
}

void GenTest()
{
    ofstream cout(name".inp");

    int n = Rand(2, 10);
    int x = Rand(1, min(n - 1, 7));
    int y = Rand(1, n - x);

    cout << n << ' ' << x << ' ' << y << '\n';
    int a = Rand(1, 1000);
    for (int i = 1; i <= n; i++)
    {
        cout << a << ' ';
    }
    cout << '\n';
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= x; j++)
        {
            cout << Rand(1, 100) << ' ';
        }
        cout << '\n';
    }

    // int n = Rand(1, 1e5);
    // int k = Rand(1, 1e5);

    // cout << n << ' ' << k << '\n';

    // for (int i = 1; i <= k; i++)
    // {
    //     int type = Rand(1, 4);

    //     if (type == 1) cout << 'A';
    //     else if (type == 2) cout << 'B';
    //     else if (type == 3) cout << 'C';
    //     else cout << 'D';
    // }

    // cout << '\n';

    // for (int i = 1; i <= n; i++)
    // {
    //     cout << Rand(1, 1e3) <<  ' ' << Rand(1, 1e3) << '\n';
    // }
}

int main()
{
    for (int i = 1; i <= ntest; i++)
    {
        GenTest();
        system(name".exe");
        system(name"_trau.exe");

        if (system("fc "name".out "name".ans") != 0)
        {
            cout << "Test: " << i << " WRONG!\n";
            return 0;
        }
        cout << "Test: " << i << " CORRECT!\n";
    }
}