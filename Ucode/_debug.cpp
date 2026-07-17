#include <bits/stdc++.h>

using namespace std;

#define name "04"
int const ntest = 1e4;

mt19937_64 rd(time(0));

long long Rand(long long l, long long r)
{
    return l + rd() * 1ll * rd() % (r - l + 1);
}

void GenTest()
{
    ofstream cout(name".inp");

    int x = 1e7;

    int n = Rand(1, 5e5);
    int q = Rand(1, 1e3);

    cout << n << ' ' << q << '\n';
    for (int i = 1; i <= n; i++) cout << Rand(-x, x) << ' ';
    cout << '\n';
    for (int i = 1; i <= q; i++) cout << Rand(-x, x) << '\n';
}

int main()
{
    for (int itest = 1; itest <= ntest; itest++)
    {
        GenTest();
        system(name".exe <"name".inp> "name".out");
        system(name"_trau.exe <"name".inp> "name".ans");

        if (system("fc "name".ans "name".out") != 0)
        {
            cout << "Test: " << itest << " WRONG!\n";
            return 0;
        }
        cout << "Test: " << itest << " CORRECT!\n";
    }
}