#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define F first
#define S second

int const N = 5009;

int k, w, h;
int a[N][N];
pair<int, int> trees[N];
int pre[N][N];

vector<int> xPos;
vector<int> yPos;

int n, m;
long long res = 1e18;

int Get(int x, vector<int> b)
{
    return lower_bound(all(b), x) - b.begin() + 1;
}

void Init()
{
    xPos.push_back(h);
    yPos.push_back(w);

    sort(all(xPos));
    sort(all(yPos));

    xPos.erase(unique(all(xPos)), xPos.end());
    yPos.erase(unique(all(yPos)), yPos.end());

    m = *xPos.rbegin();
    n = *yPos.rbegin();

    for (int i = 1; i <= k; i++)
    {
        int x = Get(trees[i].F, xPos);
        int y = Get(trees[i].S, yPos);

        a[x][y]++;
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + a[i][j];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> k >> w >> h;
    for (int i = 1; i <= k; i++)
    {
        int x, y;
        cin >> x >> y;

        xPos.push_back(x);
        yPos.push_back(y);

        trees[i] = {x, y};
    }

    if (k & 1)
    {
        cout << -1;
        return 0;
    }

    Init();

    for (int i = 0; i < xPos.size(); i++)
    {
        for (int j = 0; j < yPos.size(); j++)
        {
            if (pre[i + 1][j + 1] == k / 2)
            {
                res = min(res, 1ll * xPos[i] * yPos[j]);
            }
        }
    }

    cout << 1ll * w * h - res;

    return 0;
}