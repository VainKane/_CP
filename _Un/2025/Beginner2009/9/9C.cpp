#include <bits/stdc++.h>

using namespace std;

int n;
int u;
int v;

pair<int, int> a[(int)3e5 + 10];
int res = INT_MAX;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> u >> v;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }

    sort(a, a + n);

    int l = 0;
    int c1 = 0;
    int c2 = 0;

    for (int r = 0; r < n; r++)
    {
        if (a[r].second == 1) c1++;
        else c2++;

        while (c1 >= u && c2 >= v && l < n)
        {
            res = min(res, a[r].first - a[l].first);
            
            if (a[l].second == 1) c1--;
            else c2--;
            l++;
        }
    }

    if (res == INT_MAX) res = -1;

    cout << res;

    return 0;
}