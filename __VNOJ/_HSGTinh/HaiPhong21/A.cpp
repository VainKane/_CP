#include <bits/stdc++.h>

using namespace std;

string s;

string Solve()
{
    string res = "";
    for (auto ch : s) if (islower(ch) || isupper(ch)) res += ch;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    getline(cin, s);
    cout << Solve();

    return 0;
}