#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define sz(v) ((int)v.size())
#define F first
#define S second

int const N = 109;

int n;
bool a[N][N];
bool b[N][N];

int cntA[2], cntB[2];

vector<pair<int, int>> res;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) FOR(j, 1, n) cin >> a[i][j];
    FOR(i, 1, n) FOR(j, 1, n) cin >> b[i][j];

    FOR(i, 1, n)
    {
        REP(j, 2) cntA[j] = cntB[j] = 0;
        FOR(j, 1, n) 
        {
            cntA[a[i][j]]++;
            cntB[b[i][j]]++;
        }

        bool changed = false;
        REP(j, 2) if (cntA[j] != cntB[j])
        {
            if (cntA[j] != cntB[!j])
            {
                cout << -1;
                return 0;
            }
            changed = true;
        }

        if (changed) res.push_back({2, i});
    }

    FORD(i, n, 1) FORD(j, i, 1)

    return 0;
}