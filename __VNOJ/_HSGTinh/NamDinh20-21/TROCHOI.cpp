#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define name "TROCHOI"

int const N = 1e4 + 5;

int n;
pair<string, int> a[N];

int Count(string s)
{
    int res = 0;
    for (auto ch : s) res += isdigit(ch);
    return res;
}

bool cmp(pair<string, int> a, pair<string, int> b)
{
    int x = Count(a.F);
    int y = Count(b.F);
    if (x != y) return x < y;
    return a.S < b.S;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++) 
    {
        string s; cin >> s;
        a[i] = {s, i};
    }

    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; i++) cout << a[i].F << '\n';

    return 0;
}