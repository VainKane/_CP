#include <bits/stdc++.h>

using namespace std;

#define name "password"

int const N = 57;

int n;
int a[N];
int c[N];

string res = "";
char ch = 'a';

vector<int> len;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    int last = 0;
    int s = 0;

    for (int i = n; i >= 1; i--)
    {
        c[i] = a[i] - 2 * a[i + 1] + a[i + 2];
        s += c[i] * i;
        
        if (c[i] < 0) 
        {
            cout << "No solution.";
            return 0;
        }
    }

    if (s != n)
    {
        cout << "No solution.";
        return 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= c[i]; j++) len.push_back(i);
    }

    int l = 0;
    int r = len.size() - 1;

    while (l <= r)
    {
        if (ch == 'a')
        {
            res += string(len[r], ch);
            ch = 'b';
            r--;
        }
        else
        {
            res += string(len[l], ch);
            ch = 'a';
            l++;
        }
    }

    cout << res;

    return 0;
}