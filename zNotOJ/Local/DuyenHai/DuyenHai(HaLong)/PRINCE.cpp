#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define pii pair<int, int>
#define F first
#define S second
#define name "PRINCE"

int const N = 1e5 + 5;

int n;
int k;

string s;
pii a[N];

int dx[4] = {1, 1, -1, -1};
int dy[4] = {1, -1, 1, -1};

bool c[1009][1009];

vector<int> b;

int Direct(char s)
{
    int res = 0;
    if (s == 'B') res = 1;
    else if (s == 'C') res = 2;
    else if (s == 'D') res = 3;

    return res;
}

void Sub2()
{
    for (int i = 1; i <= n; i++)
    {
        c[a[i].F][a[i].S] = true;
    }

    int x = a[1].F;
    int y = a[1].S;

    c[x][y] = false;

    for (int i = 1; i <= k; i++)   
    {
        int d = Direct(s[i]);
        int minD = 1e9;
        pii minPos = {0, 0};
        for (int p = 1; p <= 1000; p++)
        {
            int u = x + dx[d] * p;
            int v = y + dy[d] * p;

            if (u < 0 || v < 0) continue;
            if (u > 1000 || v > 1000) continue;

            int diff = (u - x) * (u - x) + (y - v) * (y - v);
            if (diff > minD) continue;
            if (!c[u][v]) continue;

            minD = diff;
            minPos = {u, v};
        }

        if (minPos.F * minPos.S == 0) continue;
        x = minPos.F;
        y = minPos.S;
    }

    cout << x << ' ' << y;
}

void Sub1()
{
    int d = Direct(s[1]);
    for (int i = 1; i <= n; i++)
    {
        int u = (a[i].F - a[1].F) / dx[d];
        int v = (a[i].S - a[1].S) / dy[d];
        if (u == v && u > 0)
        {
            b.push_back(u);
        }
    }

    b.push_back(0);

    sort(all(b));
    b.erase(unique(all(b)), b.end());

    int p = min(k, (int)(b.size() - 1));

    cout << a[1].F + dx[d] * b[p] << ' ' << a[1].S + dy[d] * b[p];
}

bool CheckSub1()
{
    for (int i = 2; i <= k; i++)
    {
        if (s[i] != s[i - 1]) return false;
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> k;
    cin >> s;

    s = " " + s;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].F >> a[i].S;
    }

    Sub1();

    return 0;
}