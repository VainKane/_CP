#include <bits/stdc++.h>

using namespace std;

int Cal(string &a, string &b)
{
    int res = 0;
    for (int i = 0; i < min(a.size(), b.size()) && a[i] == b[i]; i++) res++;
    return res;
}

int n;
string a[30009];

int q;
string s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen("14D.inp", "r", stdin);
    freopen("14D.ans", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    cin >> q;

    while (q--)
    {
        cin >> s;
        int res = 0;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] == s)
            {
                res += s.size() + 1;
                break;
            }
            
            int k = Cal(a[i], s);
            res += k + 1;
        }

        cout << res << '\n';
    }

    return 0;
}