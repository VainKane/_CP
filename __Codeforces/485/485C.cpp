#include <bits/stdc++.h>

using namespace std;

#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define BIT(i, x) (((x) >> (i)) & 1)
#define MK(i) (1ll << (i))

long long Solve(long long l, long long r)
{
    long long res = l;
    REP(i, 61) if (!BIT(i, l))
    {
        if ((res | MK(i)) > r) return res;
        res |= MK(i);
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    while (n--)
    {
        long long l, r;
        cin >> l >> r;
        cout << Solve(l, r) << '\n';
    }

    return 0;
}
