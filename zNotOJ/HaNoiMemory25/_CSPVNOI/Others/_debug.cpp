#include <bits/stdc++.h>

using namespace std;

#define name "SUBSEQ"
#define file "csphn_subseq"
int const ntest = 1e4;

mt19937_64 rd(time(0));

long long Rand(long long l, long long r)
{
    return l + rd() * 1ll * rd() % (r - l + 1);
}

void GenTest()
{
    ofstream cout(name".inp");

    int const oo = 1e3;

    int n = Rand(1, 1e3);
    cout << n << ' ' << Rand(1, n) << '\n';
    while (n--) cout << Rand(-oo, 0) << '\n';
}

int main()
{
    for (int i = 1; i <= ntest; i++)
    {
        GenTest();
        system(file".exe");
        system(file"_trau.exe");

        if (system("fc "name".out "name".ans") != 0)
        {
            cout << "Test: " << i << " WRONG!\n";
            return 0;
        }
        cout << "Test: " << i << " CORRECT!\n";
    }

    return 0;
}