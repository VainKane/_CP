#include <bits/stdc++.h>

using namespace std;

int n;
set<pair<int, int>> visisted;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    while (n--)
    {
        int x1, x2, y1, y2;
        cin >> x1 >> x2 >> y1 >> y2;

        for (int i = x1; i < x2; i++)
        {
            for (int j = y1; j < y2; j++)
            {
                visisted.insert({i, j});
            }
        }
    }

    cout << visisted.size();

    return 0;
}