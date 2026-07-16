#include <bits/stdc++.h>

using namespace std;

#define name "23E"
int const ntest = 1e4;

mt19937_64 rd(time(0));

long long Rand(long long l, long long r)
{
    return l + rd() * 1ll * rd() % (r - l + 1);
}

void GenTest()
{
    ofstream cout(name".inp");

    int n = Rand(1, 100);
    int k = Rand(1, 50);

    cout << n << ' ' << k << '\n';

    for (int i = 1; i <= n; i++)
    {
        int d = Rand(1, 100);
        cout << d << ' ';
    }
}

int main()
{
    for (int itest = 1; itest <= ntest; itest++)
    {
        GenTest();
        system(name".exe");
        system(name"_trau.exe");

        if (system("fc "name".out "name".ans") != 0)
        {
            cout << "Test: " << itest << " WRONG\n";
            return 0;
        }
        cout << "Test: " << itest << " CORRECT\n";
    }
}