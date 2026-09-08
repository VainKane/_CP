#include <bits/stdc++.h>

using namespace std;

int const ntest = 1;
#define name "skwthr"
#define file "M"

mt19937_64 rd(time(0));

long long Rand(long long l, long long r)
{
    return l + rd() * 1ll * rd () % (r - l + 1);
}

void GenTest()
{
    ofstream cout(name".inp");

    int t = Rand(1, 500);
    cout << t << '\n';

    while (t--)
    {
        int r = Rand(2, 10);
        int c = Rand(2, 10);
        int a = Rand(r / 2, r);
        int b = Rand(c / 2, c);
        int n = Rand(1, 30);

        cout << '\n';
        cout << r << ' ' << c << ' ' << Rand(1, 6) << '\n';
        cout << a << ' ' << b << ' ' << Rand(1, r - a + 1) << ' ' << Rand(1, c - b + 1) << ' ' << Rand(1, 3) << '\n';
        cout << n << '\n';
        
        for (int i = 1; i <= n; i++) 
        {
            for (int x = 1; x <= r; x++) for (int y = 1; y <= c; y++) cout << Rand(0, 1) << ' ';
            cout << '\n';
        }
    }
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
        cout << "Test: " << i << << " CORRECT!\n";
    }

    return 0;
}