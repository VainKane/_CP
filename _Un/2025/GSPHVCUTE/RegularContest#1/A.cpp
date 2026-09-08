#include <bits/stdc++.h>

using namespace std;

#define name "password"

string s;
int x;

int res = 0;

int main()
{
    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);
    
    cin >> s >> x;
    for (auto ch : s) res += (ch - 'a' + x) % 26;
    cout << res;
}