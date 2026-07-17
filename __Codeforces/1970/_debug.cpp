#include <bits/stdc++.h>

using namespace std;

#define name "1970E3"
int const ntest = 1e4;

mt19937_64 rd(time(0));

long long Rand(long long l, long long r)
{
    return l + rd() * 1ll * rd() % (r - l + 1);
}

void GenTest()
{
    ofstream cout(name".inp");

    int n = Rand(1, 1e9);
    int m = Rand(1, 100);
    int oo = 1e3;

    cout << m << ' ' << n << '\n';
    for (int i = 1; i <= m; i++) cout << Rand(0, oo) << ' ';
    cout << '\n';
    for (int i = 1; i <= m; i++) cout << Rand(0, oo) << ' ';
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