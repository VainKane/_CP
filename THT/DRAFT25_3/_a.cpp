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

int t;
int m;
__int128 n;

mii factorize(__int128 tmp) {
    mii factor;
    int i = 2;
    while (i * i <= tmp) {
        while (tmp % i == 0) factor[i]++, tmp /= i;
        ++i;
    }
    if (tmp > 1) factor[tmp]++;
    return factor;
}

mii factor;
mii tmp;
ll cnt = 0;
void f(auto cur) {
    if (cur == factor.end()) {
        __int128 what = 1;
        for (const pii &p: tmp) {
            for (int j = 0; j < p.ss; ++j) what *= p.ff;
        }
        if (what < n and n % what and n * n % what == 0) cnt++;
        return;
    }

    for (int m = 0; m <= cur->ss * 2; ++m) {
        tmp[cur->ff] = m;
        f(next(cur));
        tmp[cur->ff] = 0;
    }
}

void solve() {
    cin >> m;
    assert(m <= 1e3 and t <= 10);
    n = (__int128)m * (m + 1) * (m + 2);
    factor = factorize(n);
    cnt = 0;
    f(factor.begin());
    cout << cnt << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) solve();
    return 0;
}
