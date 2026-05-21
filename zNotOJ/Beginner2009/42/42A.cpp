#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second

int const N = 1e5 + 5;

int n, k;
int a[N];

priority_queue<pair<int, int>> pq;
long long res = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++)
    {
        pq.push({a[i], i});
        if (pq.size() < k) continue;

        long long p = 1;
        pair<int, int> b[4];
        
        for (int j = 1; j <= 3; j++)
        {
            while (!pq.empty() && i - pq.top().S > k) pq.pop();
            
            b[j] = pq.top();
            p *= b[j].F;
            pq.pop();
        }

        for (int i = 1; i <= 3; i++) pq.push(b[i]);
        res = max(res, p);
    }

    cout << res;

    return 0;
}