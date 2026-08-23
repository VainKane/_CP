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

int const N = 1009;
int const oo = 1e9 + 9;

int m, n, k;
int a[N][N];

int ma[N][N], mi[N][N];
deque<int> q[N];

void Solve(int val[][N])
{
    FOR(j, 1, n) q[j].clear();
    FOR(i, 1, m)
    {
        deque<int> dq;
        FOR(j, 1, n)
        {
            while (!q[j].empty() && q[j].front() <= i - k) q[j].pop_front();
            while (!q[j].empty() && a[q[j].back()][j] >= a[i][j]) q[j].pop_back();
            q[j].push_back(i);
        }

        FOR(j, 1, n)
        {
            while (!dq.empty() && dq.front() <= j - k) dq.pop_front();
            while (!dq.empty() && a[q[dq.back()].front()][dq.back()] >= a[q[j].front()][j]) dq.pop_back();
            if (!q[j].empty()) dq.push_back(j);

            if (!dq.empty()) val[i][j] = a[q[dq.front()].front()][dq.front()];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> m >> n >> k;
    FOR(i, 1, m) FOR(j, 1, n) cin >> a[i][j];

    Solve(mi);
    FOR(i, 1, m) FOR(j, 1, n) a[i][j] = -a[i][j];
    Solve(ma);

    int res = oo;
    FOR(i, k, m) FOR(j, k, n) mini(res, -ma[i][j] - mi[i][j]);
    cout << res;

    return 0;
}