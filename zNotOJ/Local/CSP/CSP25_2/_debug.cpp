#include <bits/stdc++.h>

using namespace std;

#define name "ROBOT"
int const ntest = 1e4;

mt19937_64 rd(time(0));

long long Rand(long long l, long long r)
{
    return l + rd() * 1ll * rd() % (r - l + 1);
}

void GenTest()
{
    ofstream cout(name".inp");

    int const MAX = 10;

    int n = Rand(10, MAX);
    int m = Rand(n, MAX);

    cout << n << ' ' << m << '\n';
    for (int i = 1; i <= n; i++) cout << Rand(0, 1e9) << ' ';
    cout << '\n';
    for (int i = 1; i <= m; i++) cout << Rand(0, 1e9) << ' ' << Rand(n / 100, n) << '\n';
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