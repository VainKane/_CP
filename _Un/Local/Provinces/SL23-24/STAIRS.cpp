#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define pii pair<int, int>
#define F first
#define S second

int n;
double res = 0;

vector<pii> a; 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cout << fixed << setprecision(2);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;

        a.push_back({x, y});
    }

    for (int i = 1; i < a.size(); i++)
    {
        int x = a[i].F - a[i - 1].F;
        int y = a[i].S - a[i - 1].S;
        res += sqrt((1ll * x * x) + (1ll * y * y));
    }

    cout << res;

    return 0;
}