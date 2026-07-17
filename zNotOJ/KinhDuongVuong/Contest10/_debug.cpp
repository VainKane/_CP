#include <bits/stdc++.h>

using namespace std;

#define name "DARK"
int const ntest = 1e4;

mt19937_64 rd(time(0));

long long Rand(long long l, long long r)
{
    return l + rd() * 1ll * rd() % (r - l + 1);
}

void GenTest()
{
    ofstream cout(name".inp");

    // int n = Rand(1, 8000);
    // cout << n << '\n';

    // int k = 100;
    // int a[k + 1];
    // for (int i = 1; i < k; i++) a[i] = 1;
    // a[k] = 2;

    // int a1 = Rand(1, 2);
    // cout << a1 << ' ';
    // for (int i = 2; i <= n; i++) cout << Rand(1, 1e9) << ' ';
    // cout << '\n';
    // cout << a1 << ' ';
    // for (int i = 2; i <= n; i++) cout << Rand(1, 1e9) << ' ';

    int n = Rand(1, 500);
    int m = Rand(1, 20);

    cout << n << ' ' << m << '\n';
    for (int i = 2; i <= n; i++)
    {
        cout << Rand(1, i - 1) << ' ' << i << '\n';
    }
    while (m--) cout << Rand(1, n) << ' ' << Rand(1, n) << '\n';
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