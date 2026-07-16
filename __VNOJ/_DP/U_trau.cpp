#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

int const N = 20;

int n;
int a[N][N];

int k;
int x[N];

long long res = 0;

void Try(int pos)
{
    if (pos > n)
    {
        vector<int> group[N];
        FOR(i, 1, n) group[x[i]].push_back(i);

        long long tmp = 0;
        FOR(id, 1, k) REP(i, group[id].size()) FOR(j, i + 1, group[id].size() - 1) 
            tmp += a[group[id][i]][group[id][j]];
        
        maxi(res, tmp);

        // if (maxi(res, tmp))
        // {
        //     cout << "-------------------------\n";
        //     FOR(i, 1, k) 
        //     {
        //         cout << "Group " << i << ": ";
        //         for (auto &x : group[i]) cout << x << ' ';
        //         cout << '\n';
        //     }
        //     cout << "The score: " << tmp << '\n';
        // }

        return;
    }

    FOR(i, 1, k)
    {
        x[pos] = i;
        Try(pos + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) FOR(j, 1, n) cin >> a[i][j];

    for (k = 1; k <= n; k++) Try(1);
    cout << res;

    return 0;
}