#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define name "CAU2"

string s;

bool isPalin(int l, int r)
{
    int i = l;
    int j = r;

    while (i <= j) 
    {
        if (s[i] != s[j]) return false;
        i++; j--;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".ans", "w", stdout);

    cin >> s;
    s = " " + s;
    int n = s.size() - 1;

    long long res = 0;
    FOR(a, 1, n) FOR(b, a, n) FOR(x, b + 1, n) FOR(y, x, n)
        res += (isPalin(a, b) && isPalin(x, y));

    cout << res;

    return 0;
}