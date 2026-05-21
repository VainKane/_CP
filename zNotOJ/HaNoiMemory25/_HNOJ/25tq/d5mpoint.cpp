#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

int const N = 3e5 + 5;

int n;
long long x[N], y[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) 
    {
        long long u, v;
        cin >> u >> v;
        x[i] = u + v;
        y[i] = u - v;
    }

    long long maxX = *max_element(x + 1, x + n + 1);
    long long minX = *min_element(x + 1, x + n + 1);
    long long maxY = *max_element(y + 1, y + n + 1);
    long long minY = *min_element(y + 1, y + n + 1);
    
    cout << max((maxX - minX + 1) / 2, (maxY - minY + 1) / 2);

    return 0;
}