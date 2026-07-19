#include <bits/stdc++.h>

using namespace std;

#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define sz(v) ((int)v.size())
#define MK(i) (1ll << (i))
#define F first
#define S second

int const N = 22;

int n, m;
int s = 0;

pair<int, int> a[N];
vector<int> res;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    REP(i, n)
    {
        int state; cin >> state;
        if (state) s |= MK(i);
    }

    REP(i, m)
    {
        int u, v;
        cin >> u >> v;
        a[i] = {--u, --v}; 
    }

    REP(mask, MK(m))
    {
        int state = s;
        for (int tmp = mask; tmp; tmp ^= tmp & -tmp)
        {
            int i = __builtin_ctz(tmp & -tmp);
            state ^= MK(a[i].F);
            state ^= MK(a[i].S);
        }

        if (state != MK(m + 1) - 1) continue;

        cout << __builtin_popcount(mask) << '\n';
        for (int tmp = mask; tmp; tmp ^= tmp & -tmp)
        { 
            cout << __builtin_ctz(tmp & -tmp) + 1 << ' ';
        }
        return 0;
    }

    cout << "-1\n";

    return 0;
}