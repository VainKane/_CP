#include <bits/stdc++.h>
using namespace std;

#define cout cerr
#define TASKNAME ""
#define sp ' '
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b) for (int i = (a), _b = (b); i >= _b; --i)

template<typename T> bool mini(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> bool maxi(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

using ll = long long;
using pii = pair<int, int>;

const int maxn = 105;
int n;
bool a[maxn][maxn], b[maxn][maxn];

void enter() {
    cin >> n;
    
    FOR(i, 1, n) FOR(j, 1, n) {
        int tmp; cin >> tmp;
        a[i][j] = tmp;
    }

    FOR(i, 1, n) FOR(j, 1, n) {
        int tmp; cin >> tmp;
        b[i][j] = tmp;
    }
}

void sub2() {
    static int perm[11];
    FOR(i, 1, n) perm[i] = i;

    int res = INT_MAX;
    static int best[11];

    do {
        int cnt = (int)n * (n - 1) / 2;
        FOR(i, 1, n) cnt += abs(i - perm[i]);

        int diff = 0;

        static int d[11];
        FOR(i, 1, n) {
            d[i] = 0;
            FOR(j, 1, n) d[i] += b[i][j] ^ a[i][perm[j]];
            diff += min(d[i], n - d[i]);
        }

        if (diff <= 1 and mini(res, cnt)) memcpy(best, perm, sizeof perm);
    } while (next_permutation(perm + 1, perm + 1 + n));

    
    vector<pii> actions;

    cout << res << endl;
    for (const auto &[t, x]: actions) cout << t << sp << x << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    if (fopen(TASKNAME".inp", "r")) {
        freopen(TASKNAME".inp", "r", stdin);
        freopen(TASKNAME".out", "w", stdout);
    }

    enter();

    if (n <= 10) sub2();
    else return 1;

    return 0;
}