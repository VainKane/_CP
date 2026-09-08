#include <bits/stdc++.h>

using namespace std;

struct Rock
{
    int x = 0;
    int y = 0;
    int h = 0;

    int p = 0;
};

bool cmp(Rock a, Rock b)
{
    if (a.x > b.x) return true;
    else if (a.x == b.x) return a.y > b.y;
    return false;
}

int n;
Rock a[5009];
int dp[5009];

int res = 1;
int b[5009];

deque<int> mark;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        int y;
        int h;

        cin >> x >> y >> h;
        int ma = max(x, max(y, h));
        int mi = min(x, min(y, h));

        a[i].x = x + y + h - ma - mi;
        a[i].y = ma;
        a[i].h = mi;

        a[i].p = i;
    }

    sort(a + 1, a + n + 1, cmp);
    
    dp[1] = a[1].h;
    for (int i = 2; i <= n; i++)
    {
        int k = 0;
        for (int j = 1; j < i; j++)
        {
            if (a[j].x >= a[i].x && a[j].y >= a[i].y)
            {
                if (k <= dp[j])
                {
                    b[i] = j;
                    k = dp[j];
                }
            }
        }
        dp[i] = k + a[i].h;
    }

    for (int i = 1; i <= n; i++)
    {
        if (dp[res] < dp[i]) res = i;
        // cout << b[i] << ' ';
    }

    int i = res;
    while (i)
    {
        mark.push_front(i);
        i = b[i];
    }    

    // for (auto val : mark) cout << val << ' ';

    cout << dp[res] << '\n';
    cout << mark.size() << '\n';
    for (auto val : mark) cout << a[val].p << ' ' << a[val].x << ' ' << a[val].y << ' ' << a[val]. h << '\n';

    return 0;
}