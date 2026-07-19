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
#define ff first
#define ss second
#define pb push_back
#define sp ' '
#define endl '\n'
#define TASKNAME "TASKNAMEGOESHERE"

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
using mii = map<int, int>;
using mll = map<long long, long long>;
using vi2d = vector<vector<int>>;

template<typename T> bool mini(T &a, const T &b) {
     return a > b ? a = b, 1 : 0;   
}

template<typename T> bool maxi(T &a, const T &b) {
     return a < b ? a = b, 1 : 0;   
}

int const N = 209;

int n, q;
int a[N];
int dp[N][N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    FOR(i, 1, n) cin >> a[i];

    while (q--)
    {
        int type, l, r, x;
        cin >> type;
        
        if (type == 1)
        {
            cin >> l >> r >> x;
            FOR(i, l, r) a[i] += x;
        }
        else
        {
            cin >> l >> r;
            
            memset(dp, 0, sizeof dp);
            dp[l - 1][0] = 0;

            FOR(i, l, r) FOR(j, 1, r - l + 1)
            {
                int ma = a[i], mi = a[i];
                FORD(p, i, l)
                {
                    maxi(ma, a[p]), mini(mi, a[p]);
                    maxi(dp[i][j], dp[p - 1][j - 1] + ma - mi);
                }
            }

            cout << *max_element(dp[r] + 1, dp[r] + r - l + 2) << '\n';
        }
    }

    return 0;
}