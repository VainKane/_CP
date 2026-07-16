#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define BIT(i, x) (((x) >> (i)) & 1)
#define MK(i) (1LL << (i))
#define all(v) v.begin(), v.end()
#define sz(v) ((int)v.size())
#define F first
#define S second

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int m, n;
vector<vector<bool>> a;
vector<vector<int>> cnt;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--)
    {
        cin >> m >> n;

        a.assign(m + 5, vector<bool> (n + 5, 0));
        cnt.assign(m + 5, vector<int> (n + 5, 0));
        
        int cnt1 = 0;

        FOR(i, 1, m) FOR(j, 1, n) 
        {
            char ch; cin >> ch;
            a[i][j] = ch - '0';
            cnt1 += a[i][j];
        }

        FORD(i, m, 1) FOR(j, 1, n) cnt[i][j] = cnt[i + 1][j] + a[i][j];

        cout << 1LL * (cnt1 / 2) * (cnt1 - cnt1 / 2) << '\n';
        
        int need = cnt1 / 2;
        int cntD = m;

        FOR(j, 1, n)
        {
            if (need <= 0) 
            {
                FOR(i, 1, cntD) cout << 'D';
                cntD = 0;
                cout << 'R';
            }
            else if (cnt[1][j] <= need) 
            {
                need -= cnt[1][j];
                cout << 'R';
            }
            else FOR(i, 1, m)
            {
                if (cnt[i][j] == need)
                {
                    need = -1;
                    cout << 'R';
                }

                cout << 'D';
                cntD--;
            }
        }

        cout << '\n';
    }

    return 0;
}