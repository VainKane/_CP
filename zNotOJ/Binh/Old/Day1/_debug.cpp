#include <bits/stdc++.h>

using namespace std;

int const ntest = 1e4;
#define name "E"

mt19937_64 rd(time(0));

long long Rand(long long l, long long r)
{
    return l + rd() * 1ll * rd() % (r - l + 1);
}

void GenTest()
{   
    ofstream cout(name".inp");

    int x = 1e3;

    int n = Rand(2, x);
    int k = Rand(1, n - 1);

    cout << n << ' ' << k << '\n';
    for (int i = 2; i <= n; i++) cout << Rand(1, i - 1) << ' ' << i << '\n';
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