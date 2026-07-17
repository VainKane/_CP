#include <bits/stdc++.h>

using namespace std;

#define name "14D"
int const ntest = 1e6;

mt19937_64 rd(time(0));

long long Rand(long long l, long long r)
{
    return l + rd() * 1ll * rd() % (r - l + 1);
}

void GenTest()
{
    ofstream cout(name".inp");

    int n = Rand(1, 30000);
    int q = Rand(1, n);

    string s[n + 3];

    cout << n << '\n';
    for (int i = 1; i <= n; i++)
    {
        int l = Rand(1, 30);
        s[i] = "";
        for (int j = 1; j <= l; j++)
        {
            int a = Rand('a', 'z');
            cout << (char)a;
            s[i] += (char)a;
        }
        cout << '\n';
    }

    cout << q << '\n';

    for (int i = 1; i <= q; i++)
    {
        int type = Rand(1, 3);

        if (type == 1)
        {
            int k = Rand(1, n);
            cout << s[k] << '\n';
        }
        else
        {
            int l = Rand(1, 30);
            for (int j = 1; j <= l; j++)
            {
                int a = Rand('a', 'z');
                cout << (char)a;
            }
            cout << '\n';
        }
    }
}

int main()
{
    for (int itest = 1; itest <= ntest; itest++)
    {
        GenTest();
        system(name".exe");
        system(name"_trau.exe");
        
        if (system("fc "name".ans "name".out") != 0)
        {
            cout << "Test " << itest << " WRONG!\n";
            return 0;
        }
        cout << "Test " << itest << " CORRECT!\n";
    }
}