#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _ a = (a); i >= _a; i--)
#define sz(v) ((int)v.size())

int const N = 1e5 + 5;
int const oo = 1e9 + 1;

int n;
int a[N];

int res[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--)
    {
        cin >> n;
        FOR(i, 1, n) cin >> a[i];

        memset(res, 0, sizeof res);

        FOR(i, 1, n) FOR(j, i + 1, n) if (a[i] == a[j])
        {
            if (*max_element(a + i, a + j + 1) <= a[i]) 
            {
                res[i]++;
                res[j]++;
            }
        }

        FOR(i, 1, n) cout << res[i] << ' ';
        cout << '\n';
    }

    return 0;
}