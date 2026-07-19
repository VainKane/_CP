#include <bits/stdc++.h>

using namespace std;

#define name "CAU2"
int const ntest = 1e4;

mt19937_64 rd(time(0));

long long Rand(long long l, long long r)
{
    return l + rd() * 1ll * rd() % (r - l + 1);
}

void GenTest()
{
    ofstream cout(name".inp");

    int n = Rand(1, 3e5);
    int m = Rand(1, 3e5);
    
    cout << n << ' ' << m << '\n';
    for (int i = 1; i <= n; i++)
    {
        int len = Rand(1, 10);
        while (len--) cout << (char)Rand('a', 'b');
        cout << '\n';
    }
    for (int i = 1; i <= m; i++)
    {
        int len = Rand(1, 10);
        while (len--) cout << (char)Rand('a', 'b');
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

    return 0;
}