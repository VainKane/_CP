#include <bits/stdc++.h>

using namespace std;

#define name "lcs"

int a, b, c;    

string A = "";
string B = "";
string C = "";

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> a >> b >> c;

    int k = max({a, b, c});

    if (a == k) A = string(a, '1'); 
    else if (b == k) B = string(b, '1');
    else if (c == k) C = string(c, '1');

    if (!A.size()) A = string(a, '0');
    if (!B.size()) B = string(b, '0');
    if (!C.size()) C = string(c, '0'); 

    cout << B + C << '\n' << C + A << '\n' << A + B;

    return 0;
}