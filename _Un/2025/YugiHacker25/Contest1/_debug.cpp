#include <bits/stdc++.h>

using namespace std;

#define name "H"
#define ioname "H"
int const ntest = 1e4;

mt19937_64 rd(time(0));

long long Rand(long long l, long long r)
{
    return l + rd() * 1ll * rd() % (r - l + 1);
}

void GenTest()
{
    ofstream cout(ioname".inp");

    int oo = 1e9;
    int q = Rand(1, 1e4);

    cout << q << '\n';
    while (q--)
    {
        int type = Rand(1, 3);
        if (type == 1)
        {
            int l = Rand(1, oo);
            cout << "? " << Rand(1, 10) << ' ' << l << ' ' << Rand(l, oo);
        }
        else
        { 
            cout << (type == 2 ? "+ " : "- ");
            cout << Rand(1, oo);
        }

        cout << '\n';
    }

    // int n = Rand(1, 2e5);
    // int q = Rand(1, 2e5);

    // int len = Rand(1, 20);

    // int a[n + 5];

    // int j = 1;
    // while (j < n)
    // {
    //     int d = Rand(1, len);
    //     for (int i = 1; i <= len * d; i += d) 
    //     {
    //         if (j > n) break;
    //         a[++j] = i;
    //     }
    // }
    
    // random_shuffle(a + 1, a + n + 1);

    // cout << n << ' ' << q << '\n';
    // for (int i = 1; i <= n; i++) cout << a[i] << ' ';
    // cout << '\n';
    // while (q--) 
    // {
    //     int l = Rand(1, n);
    //     cout << l << ' ' << Rand(l, min(n, l + len - 1)) << '\n';
    // }
}

int main()
{
    for (int i = 1; i <= ntest; i++)
    {
        GenTest();
        system(name".exe");
        system(name"_trau.exe");

        if (system("fc "ioname".out "ioname".ans") != 0)
        {
            cout << "Test: " << i << " WRONG!\n";
            return 0;
        }

        cout << "Test: " << i << " CORRECT!\n";
    }

    return 0;
}