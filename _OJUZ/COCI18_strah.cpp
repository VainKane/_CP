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

int const N = 2009;

int m, n;
char a[N][N];

int h[N];
int l[N], r[N];

ll Cal(int x) { return 1LL * x * (x + 1) / 2; }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> m >> n;
    FOR(i, 1, m) FOR(j, 1, n) cin >> a[i][j];

    h[0] = h[n + 1] = -1;
    ll res = 0;

    FOR(i, 1, m)
    {
        FOR(j, 1, n) h[j] = a[i][j] == '#' ? 0 : h[j] + 1;
        vector<int> st;

        FOR(j, 1, n + 1)
        {
            while (!st.empty() && h[st.back()] > h[j])
            {
                r[st.back()] = j;
                st.pop_back();
            }
            st.push_back(j);
        }

        st.clear();
        FORD(j, n, 0)
        {
            while (!st.empty() && h[st.back()] >= h[j])
            {
                l[st.back()] = j;
                st.pop_back();
            }
            st.push_back(j);
        }

        FOR(j, 1, n) res += 1LL * Cal(h[j]) * (Cal(j - l[j]) * (r[j] - j) + Cal(r[j] - j) * (j - l[j]) - (r[j] - j) * (j - l[j]));
    }

    cout << res;

    return 0;
}