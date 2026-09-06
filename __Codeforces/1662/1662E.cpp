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

int const N = 11;
int const M = 1e4 + 5;

int n, m;

int x[N];
bool a[N][M];

int w[M], id[M];
int res[M];

bool cmp(int i, int j) { return w[i] < w[j]; }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--)
    {
        cin >> n >> m;
        REP(i, n) cin >> x[i];
        REP(i, n) FOR(j, 1, m)
        {
            char ch; cin >> ch;
            a[i][j] = ch - '0';
        }

        FOR(i, 1, m) id[i] = i;

        int tmp = -1;
        REP(mask, MK(n))
        {
            memset(w, 0, (m + 1) * sizeof(int));
            int sum = 0;

            REP(i, n) 
            {
                int delta = BIT(i, mask) ? 1 : -1;
                FOR(j, 1, m) w[j] += delta * a[i][j];
                sum -= delta * x[i];
            }

            sort(id + 1, id + m + 1, cmp);
            FOR(i, 1, m) sum += i * w[id[i]];

            if (maxi(tmp, sum)) FOR(i, 1, m) res[id[i]] = i;
        }

        FOR(i, 1, m) cout << res[i] << ' ';
        cout << '\n';
    }

    return 0;
}