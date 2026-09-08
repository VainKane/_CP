#include <bits/stdc++.h>

using namespace std;

#define name "SEQ"
int const ntest = 1e4;

mt19937_64 rd(time(0));

long long Rand(long long l, long long r)
{
    return l + rd() * 1ll * rd() % (r - l + 1);
}

void GenTest()
{
    ofstream cout(name".inp");

    int t = Rand(1, 1000);
    int oo = 1e9;

    cout << t << '\n';
    while (t--)
    {
        int type = Rand(1, 2);
        cout << type << ' ';

        if (type == 1) cout << Rand(1, oo) << '\n';
        else
        {
            int l = Rand(1, oo);
            cout << l << ' ' << Rand(l, oo) << '\n';
        }
    }
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