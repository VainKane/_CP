#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define name "chemistry"

int const N = 205;

int t;
int n;
int v[N];
int x[N];
int s[4];

bool cnt[4];

int ma;
char res[N];

string str = " PVH";

void Try(int pos)
{
    if (pos > n)
    {
        memset(s, 0, sizeof s);
        memset(cnt, false, sizeof cnt);

        FOR(i, 1, n) 
        {
            s[x[i]] ^= v[i];
            cnt[x[i]] = true;
        }
        int tmp = s[1] + s[2] + s[3];

        if (tmp > ma && cnt[1] * cnt[2] * cnt[3])
        {
            FOR(i, 1, n) res[i] = str[x[i]];
            ma = tmp;
        }
        return;
    }

    FOR(i, 1, 3) x[pos] = i, Try(pos + 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".ans", "w", stdout);

    cin >> t;
    while (cin >> n)
    {
        if (n == 0) return 0;

        ma = 0;
        FOR(i, 1, n) cin >> v[i];
        Try(1);

        FOR(i, 1, n) cout << res[i];
        // cout << ' ' << ma;
        cout << '\n';
    }

    return 0;
}