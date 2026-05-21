#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second

int const N = 1e5 + 5;

int n, w, h;
pair<int, int> a[N];

priority_queue<int> pq;
long long res = 1e18;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> w >> h;
    for (int i = 1; i <= n; i++) cin >> a[i].F >> a[i].S;

    if (n & 1)
    {
        cout << -1;
        return 0;
    }

    sort(a + 1, a + n + 1);

    for (int i = 1; i <= n; i++)
    {
        pq.push(a[i].S);

        if (a[i].F == a[i + 1].F) continue;
        
        int x;
        while (pq.size() > n / 2) 
        {
            x = pq.top();
            pq.pop();
        }

        while (!pq.empty() && pq.top() == x) pq.pop();

        if (pq.size() == n / 2) res = min(res, 1ll * pq.top() * a[i].F);
    }

    cout << 1ll * w * h - res;

    return 0;
}