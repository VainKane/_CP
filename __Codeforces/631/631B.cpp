#include <bits/stdc++.h>

using namespace std;

int const N = 5009;

#define F first
#define S second

int n, m, k;
pair<int, int> row[N];
pair<int, int> col[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++)
    {
        int type;
        cin >> type;

        if (type == 1)
        {
            int r, a;
            cin >> r >> a;

            row[r] = {i, a};
        }
        if (type == 2)
        {
            int c, a;
            cin >> c >> a;

            col[c] = {i, a};
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (row[i] > col[j]) cout << row[i].S;
            else cout << col[j].S;
            cout << ' ';
        }
        cout << '\n';
    }

    return 0;
}