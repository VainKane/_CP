#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return (a.second < b.second);
}

int t;
int n;

int k;

pair<int, int> a[(int)1e5 + 10];
int b[(int)1e5 + 10];

int res[(int)1e5 + 10];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> n >> k;

        for (int i = 0; i < n; i++)
        {
            int val;
            cin >> val;

            a[i].first = i;
            a[i].second = val;
        }

        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }

        sort(a, a + n, cmp);
        sort(b, b + n);

        for (int i = 0; i < n; i++)
        {
            res[a[i].first] = b[i];
        }

        for (int i = 0; i < n; i++) cout << res[i] << ' ';
        cout << '\n';
    }

    return 0;
}