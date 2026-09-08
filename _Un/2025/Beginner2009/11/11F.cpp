#include <bits/stdc++.h>

using namespace std;

int n;

pair<int, int> a[1009];
bool dp[1009][100009];

int s = 0;
vector<int> res;

bool mark[1009][100009];
pair<int, int> pos;

int ma = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("11F.inp", "r", stdin);
    // freopen("11F.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].first;
        a[i].second = i;
        s += a[i].first;
        dp[i][0] = 1;
    }

    dp[0][0] = 1;

    sort(a + 1, a + n + 1, greater<pair<int, int>> ());

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= s; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= a[i].first)
            {
                dp[i][j] = dp[i][j] | dp[i - 1][j - a[i].first];
            }

            if (dp[i - 1][j - a[i].first]) 
            {
                // b[i][j] = {i - 1, j - a[i].first};
                mark[i][j] = 1;
            }
            // else if (dp[i - 1][j]) b[i][j] = {i - 1, j};

            if (dp[i - 1][j])
            {
                if (j * 2 <= s && (j + a[i].first) * 2 > s)
                {
                    if (ma < j + a[i].first)
                    {
                        pos = {i, j + a[i].first};
                        ma = j + a[i].first;
                    }
                }
            }
        }
    }

    while (pos.first != 0 && pos.second != 0)
    {
        if (mark[pos.first][pos.second]) res.push_back(a[pos.first].second);
        
        if (dp[pos.first - 1][pos.second - a[pos.first].first])
        {
            pos.second = pos.second - a[pos.first].first;
        }
        pos.first--;
    }

    cout << res.size() << '\n';
    for (auto val : res) cout << val << ' ';

    return 0;
}