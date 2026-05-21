#include <bits/stdc++.h>

using namespace std;

#define file "X"
#define name "chemistry"

int const ntest = 10;

mt19937_64 rd(time(0));

long long Rand(long long l, long long r)
{
    return l + rd() * 1ll * rd() % (r - l + 1);
}

void GenTest()
{
    ofstream cout(name".inp");

    int t = 1;
    int tests = Rand(2, 2);

    cout << t << '\n';

    while (tests--)
    {
        int n = Rand(4, 4);
        cout << n << '\n';

        for (int i = 1; i <= n; i++) cout << Rand(0, 600) << ' ';
        cout << '\n';
    }
    cout << 0;
}

int main()
{
    for (int i = 1; i <= ntest; i++)
    {
        GenTest();
        system(file".exe");
        system(file"_trau.exe");

        if (system("fc "name".ans "name".out") != 0)
        {
            cout << "Test: " << i << " WRONG!\n";
            return 0;
        }
        cout << "Test: " << i << " CORRECT!\n";
    }

    return 0;
}