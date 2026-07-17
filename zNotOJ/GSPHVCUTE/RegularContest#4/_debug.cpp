#include <bits/stdc++.h>

using namespace std;

#define name "C"
#define file "remainder"

int const ntest = 1e4;

mt19937_64 rd(time(0));

long long Rand(long long l, long long r)
{
    return l + rd() * rd() % (r - l + 1);
}

void GenTest()
{
    ofstream cout(file".inp");

    long long x = 1e18;
    cout << Rand(-x, x) << ' ' << Rand(-x, x);
}

int main()
{
    for (int i = 1; i <= ntest; i++)
    {
        GenTest();
        system(name".exe");
        system(name"_trau.exe");

        if (system("fc "file".out "file".ans") != 0)
        {
            cout << "Test: " << i << " WRONG!\n";
            return 0;
        }

        cout << "Test: " << i << " CORRECT!\n";
    }

    return 0;
}