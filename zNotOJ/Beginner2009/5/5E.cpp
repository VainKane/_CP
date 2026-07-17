#include <bits/stdc++.h>

using namespace std;

int n;
string s;

int a[200009];
int b[200009];

int c[5][5];

int res = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> s;

    for (int i = 0; i < n; i++)
    {
        int val;
        if (s[i] == 'X') val = 0;
        else if (s[i] == 'T') val = 1;
        else val = 2;

        a[i] = b[i] = val;
    }

    sort(b, b + n);

    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i])
        {
            c[a[i]][b[i]]++;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = i + 1; j < 3; j++)
        {
            int x = min(c[i][j], c[j][i]);

            res += x;
            c[i][j] -= x;
            c[j][i] -= x;
        }
    }

    res += 2 * max(c[0][0], max(c[0][1], c[0][2]));

    cout << res;

    return 0;
}