#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define name "CULTURE"
int const ntest = 1e4;

mt19937_64 rd(time(0));

long long Rand(long long l, long long r)
{
    return l + rd() * 1ll * rd() % (r - l + 1);
}

void GenTest()
{
    ofstream cout(name".inp");

    int n = Rand(1, 1e4);

    vector<string> guys;
    cout << n << '\n';

    while (guys.size() < n)
    {
        int l = Rand(5, 10);
        string s = "";
        for (int i = 1; i <= l; i++) s += (char)Rand('a', 'z');
        guys.push_back(s);
        sort(all(guys));
        guys.erase(unique(all(guys)), guys.end());
    }

    random_shuffle(all(guys));
    for (auto val : guys) cout << val << '\n';
    random_shuffle(all(guys));
    for (auto val : guys) cout << val << '\n';
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