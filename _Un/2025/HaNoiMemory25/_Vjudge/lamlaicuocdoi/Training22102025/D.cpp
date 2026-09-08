#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

int const N = 5e5 + 5;

int n;
char s[N];
int cnt[N];

int nxt[N];
int pos[2 * N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) 
    {
        cin >> s[i];
        cnt[i] = cnt[i - 1] + (s[i] == '0');
    }

    int last = 0;
    FORD(i, n, 0)
    {
        nxt[i] = last;
        if (s[i] == '1') last = i;
    }

    FOR(i, 1, n) if (!pos[cnt[i]]) pos[cnt[i]] = i;

    int res = n - cnt[n];

    FOR(k, 1, n) if (pos[k] && nxt[pos[k]] && pos[cnt[nxt[pos[k]]] + k])
    {
        int idx = nxt[pos[k]];
        int ans = 0;

        while (pos[cnt[idx] + k] && idx)
        {
            ans += k + 1;
            idx = nxt[pos[cnt[idx] + k]];
        }

        maxi(res, ans + k);
    }

    cout << res;

    return 0;
}