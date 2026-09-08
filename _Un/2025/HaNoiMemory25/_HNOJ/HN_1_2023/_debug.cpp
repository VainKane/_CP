#include <bits/stdc++.h>

using namespace std;

#define name "KHUDANCU"
int const ntest = 10;

mt19937_64 rd(time(0));

long long Rand(long long l, long long r)
{
    return l + rd() * 1ll * rd() % (r - l + 1);
}

void GenTest()
{
    ofstream cout(name".inp");

    int n = Rand(1, 10);
    int m = Rand(1, 10);
    int d = Rand(1, 2);
    int k = Rand(1, 3);

    cout << m << ' ' << n << ' ' << d << ' ' << k << '\n';
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int type = Rand(1, 100);
            if (type <= 30) cout << 'M';
            else if (type <= 40) cout << '.';
            else cout << 'P';
        }
        cout << '\n';
    }
}

int main()
{
    for (int i = 1; i <= ntest; i++)
    {
        GenTest();
        system(name".exe");
        system(name"_trau.exe");

        if (system("fc "name".out "name".ans") != 0)
        {
            cout << "Test: " << i << " WRONG!\n";
            return 0;
        }
        cout << "Test: " << i << " CORRECT!\n";
    }
}