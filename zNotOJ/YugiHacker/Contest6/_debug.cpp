#include <bits/stdc++.h>

using namespace std;

#define name "C"
#define ioname "nexist"
int const ntest = 1e4;

mt19937_64 rd(time(0));

long long Rand(long long l, long long r)
{
    return l + rd() * 1ll * rd() % (r - l + 1);
}

void GenTest()
{
    ofstream cout(ioname".inp");

    int n = Rand(1, 1000);
    int m = Rand(1, 1000);
    int oo = 1e9;

    while (n--) cout << (char)Rand('a', 'z');
    cout << '\n';
    while (m--) cout << (char)Rand('a', 'z');
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