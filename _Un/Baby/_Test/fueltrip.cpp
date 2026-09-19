#include <bits/stdc++.h>
using namespace std;

#define TASKNAME ""
#define sp ' '
#define endl '\n'
#define cout cerr
#define all(x) (x).begin(), (x).end()
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b) for (int i = (a), _b = (b); i >= _b; --i)

template<typename T> bool mini(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> bool maxi(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

using ll = long long;
using pii = pair<int, int>;

const int maxn = 1e5 + 5;
int n, m;
pii a[maxn], b[maxn];

void enter() {
    cin >> n >> m;
    FOR(i, 1, n) cin >> a[i].first >> a[i].second;
    FOR(i, 1, m) cin >> b[i].first >> b[i].second;
}

void sub1() {
    ll fuel = a[1].second;
    FOR(i, 1, m) {
        if (a[1].first > b[i].first) continue;
        if (a[1].first + fuel >= b[i].first) fuel += b[i].second;
        else break;
    }
    cout << fuel << endl;
}

void sub2() {
    auto chk = [](int mid) {
        int fuel = b[1].second;
        FOR(i, 1, n) {
            if (a[i].second >= mid) continue;
            int need = mid - a[i].second;
            if (a[i].first > b[1].first or need > fuel or a[i].first + a[i].second < b[1].first) return 0;
            fuel -= need;
        }
        return 1;
    };

    int l = 1, r = 2e9;
    int res = 0;
    while (l <= r) {
        int mid = ((ll)l + r) >> 1;
        if (chk(mid)) res = mid, l = mid + 1;
        else r = mid - 1;
    }

    cout << res << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    if (fopen(TASKNAME".inp", "r")) {
        freopen(TASKNAME".inp", "r", stdin);
        freopen(TASKNAME".out", "w", stdout);
    }

    enter();

    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + m);

    if (n == 1) sub1();
    else if (m == 1) sub2();
    else return 1;

    return 0;
}