#include <bits/stdc++.h>

using namespace std;

#define name "easytask"
int const ntest = 1e4;

mt19937_64 rd(time(0));

long long Rand(long long l, long long r)
{
    return l + rd() * 1ll * rd() % (r - l + 1);
}

void GenTest()
{
    ofstream cout(name".inp");

    int n = Rand(2, 1e4);
    cout << n << '\n';

    for (int i = 1; i <= n; i++)
    {
        cout << Rand(-1e2, 1e2) << ' ';
    }
}

int main()
{
    for (int i = 1; i <= ntest; i++)
    {
        GenTest();
        system(name".exe");
        system(name"_trau.exe");

        if (system("fc "name".ans "name".out") != 0)
        {
            cout << "Test: " << i << " WRONG!\n";
            return 0;
        }
        cout << "Test : " << i << " CORRECT!\n";
    }
}