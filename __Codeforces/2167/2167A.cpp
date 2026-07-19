#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

bool Solve(int x[])
{
    FOR(i, 1, 4) FOR(j, i + 1, 4) if (x[i] != x[j]) return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--)
    {
        int x[5];
        FOR(i, 1, 4) cin >> x[i];
        cout << (Solve(x) ? "YES\n" : "NO\n");
    }

    return 0;
}