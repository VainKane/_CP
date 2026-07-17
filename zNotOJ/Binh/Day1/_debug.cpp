#include <bits/stdc++.h>

using namespace std;

#define name "C"
int const ntest = 1e4;

mt19937_64 rd(time(0));

long long Rand(long long l, long long r)
{
    return l + rd() * 1ll * rd() % (r - l + 1);
}

void GenTest()
{
    ofstream cout(name".inp");

    int n = Rand(1, 1000);
    int k = Rand(1, n);
    int oo = 1e6;

    cout << n << ' ' << k << '\n';
    for (int i = 2; i <= n; i++)
    {
        cout << i << ' ' << Rand(1, i - 1) << ' '  << Rand(1, oo) << '\n';
    }
    while (k--) cout << Rand(1, n) << '\n';

    //************************Problem A
//     int oo = 1e4;
//     int n = Rand(1, 3e5);
//     int m = Rand(1, 1e5);

//     vector<int> valuesX, valuesY;

//     cout << n << '\n';
//     while (n--) 
//     {
//         valuesX.push_back(Rand(1, oo));
//         valuesY.push_back(Rand(1, oo));
//         cout << valuesX[valuesX.size() - 1] << ' ' << valuesY[valuesY.size() - 1] << '\n'; 
//     }

//     cout << m << '\n';
//     while (m--)
//     {
//         int type = Rand(1, 1);
//         int x1 = valuesX[Rand(0, valuesX.size() - 1)];
//         int x2 = Rand(x1, oo);

//         type = Rand(1, 1);
//         int y1 = valuesY[Rand(0, valuesY.size() - 1)];
//         int y2 = Rand(y1, oo);

//         cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << '\n';
//     }
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