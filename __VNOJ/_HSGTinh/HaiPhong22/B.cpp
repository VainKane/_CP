#include <bits/stdc++.h>

using namespace std;

int const N = 1e4 + 5;

int n;
string a[N];

bool cmp(string a, string b)
{
    return a + b > b + a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    sort(a + 1, a + n + 1, cmp);
    for (auto x : a) cout << x; 

    return 0;
}