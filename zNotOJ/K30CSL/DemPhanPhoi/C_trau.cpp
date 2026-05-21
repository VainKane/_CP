#include <bits/stdc++.h>

using namespace std;

#define name "C"

int n;
string s;

long long res = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".ans", "w", stdout);

    cin >> n >> s;
    s = " " + s;

    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            if (s[i] == s[j]) res++;
        }
    }

    cout << res;

    return 0;
}