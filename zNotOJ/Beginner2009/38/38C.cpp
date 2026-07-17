#include <bits/stdc++.h>

using namespace std;

int const N = 1e6 + 5;

int n;
string s;
int z[N];

int a[N];
int pre[N];
vector<int> b;

void Z()
{
    int l = 0;
    int r = 0;

    for (int i = 2; i <= n; i++)
    {
        if (i <= r) z[i] = min(z[i - l + 1], r - i + 1);
        while (i + z[i] <= n && s[z[i] + 1] == s[i + z[i]]) z[i]++;

        if (r < i + z[i] - 1)
        {
            l = i;
            r = i + z[i] - 1;
        }

        if (i + z[i] - 1 == n) b.push_back(z[i]);
        a[z[i]]++;
    }

    for (int i = n; i >= 1; i--) pre[i] = pre[i + 1] + a[i];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> s;
    s = " " + s;
    n = s.size() - 1;

    Z();
    // for (auto x : b) cout << x << ' ';
    int res = 0;
    for (int i = 0; i < b.size(); i++)
    {
        if (pre[b[i]] >= 2) res = max(res, b[i]);
    }    

    if (res == 0) cout << "No solution!";
    else for (int i = 1; i <= res; i++) cout << s[i];

    return 0;
}