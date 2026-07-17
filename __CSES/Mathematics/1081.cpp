#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, a, b) for (int i = (a), _b = (b); i >= _b; i--)

int const N = 1e6 + 5;

int cnt[N];
int cntDiv[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    FOR(i, 1, n)
    {
        int x; cin >> x;
        cnt[x]++;
    }

    FOR(i, 1, sqrt(1e6)) for (int j = i * i; j <= 1e6; j += i)
    {
        cntDiv[i] += cnt[j];
        if (i * i != j) cntDiv[j / i] += cnt[j];
    }

    FORD(i, 1e6, 1) if (cntDiv[i] >= 2)
    {
        cout << i;
        return 0;
    }

    return 0;
}