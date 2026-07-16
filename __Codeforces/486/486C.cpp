#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)

int const N = 1e5 + 5;

int n, p;
char s[N];

int Cost(char a, char b)
{
    a -= 'a';
    b -= 'a';
    return min({abs(a - b), 26 - a + b, a + 26 - b});
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> p;
    FOR(i, 1, n) cin >> s[i];

    int mid = n / 2;

    int l = p <= mid ? 1 : mid + 1;
    int r = p <= mid ? mid : n;

    FOR(i, l, r)
    {
        if (Cost(s[i], s[n - i + 1])) break;
        l++;
    }

    FORD(i, r, l)
    {
        if (Cost(s[i], s[n - i + 1])) break;
        r--;
    }

    int res = r - l + min(abs(p - l), abs(r - p));
    FOR(i, 1, mid) res += Cost(s[i], s[n - i + 1]);
    if (l > r) res = 0;

    cout << res;

    return 0;
}