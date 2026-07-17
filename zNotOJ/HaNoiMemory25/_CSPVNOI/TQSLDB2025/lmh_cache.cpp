#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int = (b), _a = (a); i >= _a; i--)

int const N = 1009;

int n, k;
int a[N];

int last[N], nxt[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    FOR(i, 1, k) cin >> a[i];

    memset(nxt, 0x3f, sizeof nxt);

    FORD(i, n, 1)
    {
        nxt[i] = last[a[i]];
        last[a[i]] = i;
    }



    return 0;
}