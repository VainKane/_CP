#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define all(v) v.begin(), v.end()
#define MK(i) (1ll << (i))

int const N = 3e5 + 5;
int const oo = 1e9 + 9;
int const LOG = 19;

int n, q;
int a[N];

int Get(int l, int r)
{
    if (l > r) return oo;
    return *max_element(a + l, a + r + 1);
}

long long Solve(int const &x)
{
    long long res = 0;

    FOR(i, 1, n) FOR(j, i + 1, n)
    {
        int m1 = Get(i, j);
        int m2 = max(Get(1, i - 1), Get(j + 1, n));
        
        res += min(m1, m2) == x;
        // if (min(m1, m2) == x) cout << i << ' ' << j << '\n';
    }   

    return 2 * res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;  
    FOR(i, 1, n) cin >> a[i];

    while (q--)
    {
        int x; cin >> x;
        cout << Solve(x) << ' ';
    }

    return 0;
}