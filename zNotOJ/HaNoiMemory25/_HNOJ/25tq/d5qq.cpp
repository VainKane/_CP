#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

int const N = 1e5 + 5;

int n;
int x[N];
int y[N];

long long Cal(int x[])
{
    int med = x[(n + 1) / 2];
    
    long long res = 0;
    FOR(i, 1, n) res += abs(x[i] - med);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> x[i] >> y[i];

    sort(x + 1, x + n + 1);
    sort(y + 1, y + n + 1);

    long long costX = Cal(x);
    long long costY = Cal(y);

    FOR(i, 1, n)
    {
        x[i] -= i - 1;
        y[i] -= i - 1;
    }

    sort(x + 1, x + n + 1);
    sort(y + 1, y + n + 1);

    cout << min(costX + Cal(y), costY + Cal(x));

    return 0;
}