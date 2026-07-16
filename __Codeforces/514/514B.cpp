#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define F first
#define S second
#define y0 __y0

int const N = 1009;

int n;
pair<int, int> a[N];

int x0, y0;
bool used[N];

bool Check(int x1, int y1, int x2, int y2, int x3, int y3)
{
    return (x2 - x1) * (y3 - y1) == (y2 - y1) * (x3 - x1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> x0 >> y0;
    FOR(i, 1, n) cin >> a[i].F >> a[i].S;

    int res = 0;

    FOR(i, 1, n) if (!used[i]) 
    {
        used[i] = true;
        FOR(j, 1, n) if (!used[j] && Check(x0, y0, a[i].F, a[i].S, a[j].F, a[j].S)) used[j] = true;
        res++; 
    }

    cout << res;

    return 0;
}