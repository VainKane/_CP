#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define name "abba"

string x, y;

bool Check(string x, string y)
{
    if (x == y) return true;
    if (x.size() > y.size()) return false;

    bool res = 0;

    if (y.back() == 'A')
    {
        string s = y;
        s.pop_back();
        
        res |= Check(x, s);
    }
    if (y.front() == 'B')
    {
        string s = y;
        reverse(all(s));
        s.pop_back();

        res |= Check(x, s);
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    for (int i = 1; i <= 3; i++)
    {
        cin >> x >> y;
        cout << (Check(x, y) ? "Yes\n" : "No\n");
    }

    return 0;
}