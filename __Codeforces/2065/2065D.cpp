#include <bits/stdc++.h>

using namespace std;

bool cmp(vector<int> &a, vector<int> &b)
{
    return a.back() > b.back();
}

int t;

int n;
int m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> n >> m;

        vector<vector<int>> a(n);

        for (int i = 0; i < n; i++)
        {
            long long sum = 0;

            for (int j = 0; j < m; j++)
            {
                int val;
                cin >> val;
                a[i].push_back(val);

                sum += 1LL * val;
            }

            a[i].push_back(sum);
        }

        sort(a.begin(), a.end(), cmp);

        long long pre[n * m + 9];

        vector<int> b;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                b.push_back(a[i][j]);
            }
        }

        pre[0] = b[0];

        long long res = 0;

        for (int i = 1; i < m * n; i++)
        {
            pre[i] = pre[i - 1] + b[i];
            res += pre[i];
        }

        cout << res + pre[0] << '\n';
    }

    return 0;
}