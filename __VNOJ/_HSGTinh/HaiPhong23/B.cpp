#include <bits/stdc++.h>

using namespace std;

int main()
{
    int res = 0;
    string s; cin >> s;
   
    for (auto ch : s) res += isdigit(ch);
    cout << res;    
   
    return 0;
}