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
#define name ""

using ll = long long;
using ii = pair<int, int>;

template <class T> bool maxi(T &x, T const &y) { return x < y ? x = y, 1 : 0; }
template <class T> bool mini(T &x, T const &y) { return x > y ? x = y, 1 : 0; }

int const N = 2e5 + 5;
int const oo = 1e9 + 9;

int n, k;
pair<int, char> a[N];
vector<int> pos[2];

int Get(int l, ll r) { return upper_bound(all(pos[l & 1]), r) - upper_bound(all(pos[l & 1]), l); };
ll C2(int x) { return 1LL * x * (x - 1) / 2; }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    FOR(i, 1, n) cin >> a[i].F;
    FOR(i, 1, n) cin >> a[i].S;

    sort(a + 1, a + n + 1);
    FOR(i, 1, n) if (a[i].S == 'L') pos[a[i].F & 1].push_back(a[i].F);

    ll res = 0;
    FOR(i, 1, n) if (a[i].S == 'R') res += Get(a[i].F, a[i].F + 2LL * k);
    
    for (int l = 1, r; l <= n; l = r)
    {
        int cnt = 0;
        for (r = l; r <= n && a[r].F == a[l].F; r++) cnt++;
        res += C2(cnt);
    }
   
    cout << res;

    return 0;
}