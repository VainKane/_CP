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
int const lim = 950;

int n, r, b, l;
ii a[N];

int res = -1;
int id[N], resId[N];

int w[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    auto startTime = chrono::high_resolution_clock::now();

    cin >> n >> r >> b;
    l = 9 * (r + 1) / 10;

    FOR(i, 1, n) cin >> a[i].F, a[i].S = i, w[i] = a[i].F;

    while (chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - startTime).count() <= lim)
    {
        shuffle(a + 1, a + n + 1, mt19937_64(time(0)));

        int idx = 0;
        int s = 0, cnt = 0;

        vector<int> st;

        FOR(i, 1, n + 1) if (idx <= b)
        {
            if (s >= l)
            {
                int j = s <= r ? ++idx : 0;
                while (!st.empty())
                {
                    id[a[st.back()].S] = j, cnt += (j != 0);
                    st.pop_back();
                }

                s = 0;
            }

            st.push_back(i);
            s += a[i].F;
        }

        while (!st.empty())
        {
            id[a[st.back()].S] = 0;
            st.pop_back();
        }

        if (idx == b && maxi(res, cnt)) FOR(i, 1, n) resId[i] = id[i];
    }

    assert(res != -1);
    FOR(i, 1, n) cout << resId[i] << ' ';

    return 0;
}