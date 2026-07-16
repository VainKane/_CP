#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

int const N = 3e5 + 5;

int n, q;
char s[N];

bool Solve(int l, int r)
{
    if (l == r) return true;
    FOR(i, l + 2, r) if (s[i] == s[i - 1] || s[i] == s[i - 2]) return false;
    return s[l + 1] != s[l];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    FOR(i, 1, n) cin >> s[i];

    while (q--)
    {
        int type, l, r;
        cin >> type >> l >> r;

        if (type == 1) swap(s[l], s[r]);
        else cout << Solve(l, r) << '\n';
    }

    return 0;
}