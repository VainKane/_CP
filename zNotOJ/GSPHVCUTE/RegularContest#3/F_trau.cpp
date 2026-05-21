#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define name "raspored"

int const N = 3e5 + 5;

int subtask;
int n, q;
int t[N], d[N];
int dd[N];

long long Solve()
{
    long long res = 0;
    long long tmp = 0;

    FOR(i, 1, n) dd[i] = d[i];
    sort(dd + 1, dd + n + 1);

    FOR(i, 1, n) 
    {
        tmp += dd[i];
        res += t[i] - tmp;
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".ans", "w", stdout);

    cin >> subtask;
    cin >> n >> q;
    FOR(i, 1, n) cin >> t[i] >> d[i];

    if (subtask == 2)
    {
        long long s = 0;
        long long tmp = 0;
        long long sum = 0;

        sort(d + 1, d + n + 1);

        FOR(i, 1, n) 
        {
            s += t[i];
            tmp += d[i];
            sum += tmp;
        }
        
        cout << s - sum;

        while (q--)
        {
            int idx, ti, di;
            cin >> idx >> ti >> di;

            s -= t[idx];
            t[idx] = ti;
            s += t[idx];

            cout << ' ' << s - sum;
        }

        return 0;
    }

    cout << Solve();
    while (q--)
    {
        int idx, ti, di;
        cin >> idx >> ti >> di;
        
        t[idx] = ti;
        d[idx] = di;

        cout << ' ' << Solve();
    }

    return 0;
}