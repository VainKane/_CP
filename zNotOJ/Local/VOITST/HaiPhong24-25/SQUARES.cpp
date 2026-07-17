#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define name "SQUARES"

int Solve(int s)
{
    int res = sqrt(s);
    FOR(a, 1, sqrt(s - 1)) res += sqrt(s - a * a) - a + 1;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    int s; cin >> s;
    cout << Solve(s);

    return 0;
}