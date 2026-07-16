#include <bits/stdc++.h>

using namespace std;

int const N = 1009;

int n;
int a[N];
int cnt = 0;

vector<int> res;

int GCD(int a, int b)
{
    int r = -1;

    while (r)
    {
        r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    res.push_back(a[1]);
    for (int i = 2; i <= n; i++)
    {
        if (GCD(a[i], a[i - 1]) != 1) res.push_back(1);
        res.push_back(a[i]);
    }

    cout << res.size() - n << '\n';
    for (auto x : res) cout << x << ' ';

    return 0;
}