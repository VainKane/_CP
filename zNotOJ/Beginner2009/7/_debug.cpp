#include <bits/stdc++.h>

using namespace std;

#define name "7D"
int const ntest = 1e8;

mt19937_64 rd(time(0));

long long Rand(long long l, long long r)
{
    assert(l <= r);
    return l + rd() * 1ll * rd() % (r - l + 1);
}

void GenTest()
{
    ofstream cout(name".inp");

    int oo = 5;
    int n = Rand(oo, oo);
    cout << n << '\n';

    for (int i = 1; i <= n; i++)
    {
        int k = Rand(oo, oo);
        while (k--) 
        {
            int r = Rand(3, 7);
            int type = Rand(0, r);
            if (type >= 2) cout << '*';
            else cout << char('a' + type);
        }
        cout << '\n';
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