#include <bits/stdc++.h>
using namespace std;

#define TASKNAME "brick"
#define ff first
#define ss second
#define pb push_back
#define sp ' '
#define endl '\n'
#define all(x) (x).begin(), (x).end()

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
using mii = map<int, int>;
using mll = map<long long, long long>;
using vi2d = vector<vector<int>>;

template<typename T> bool maxi(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

const int maxn = 1e5 + 5;
int n, l, r, k;
int a[maxn];

void enter() {
    cin.tie(0)->sync_with_stdio(0);
    if (fopen(TASKNAME".inp", "r")) {
        freopen(TASKNAME".inp", "r", stdin);
        freopen(TASKNAME".out", "w", stdout);
    }
    cin >> n >> l >> r >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];  
}

namespace sub1 {
    bool check() { return max(n, r) <= 100; }
    void solve() {
        ll best = 0;
        int cnt = 0;
        for (int x = l; x <= r; ++x) {
            if (x % k) continue;
            ll sum = 0;
            for (int i = 1; i <= n; ++i) sum += a[i] ^ x;
            cnt += best == sum;
            if (maxi(best, sum)) cnt = 1;
        }
        cout << best << endl << cnt << endl;
    }
}

namespace sub2 {
    bool check() { return l == 0 and k == 1 and r == (1 << 29) - 1; }
    int freq[29][2];
    void solve() {
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < 29; ++j) freq[j][(a[i] >> j) & 1]++;
        }

        long long res = 0;
        int cnt = 0;
        
        for (int i = 0; i < 29; ++i) {
            cnt += freq[i][0] == freq[i][1];
            res += max(freq[i][0], freq[i][1]) * (1ll << i);
        }

        cout << res << endl << (1 << cnt) << endl;
    }
}

int main() {
    enter();
    if (sub1::check()) return sub1::solve(), 0;
    if (sub2::check()) return sub2::solve(), 0;
 
    return 0;
}