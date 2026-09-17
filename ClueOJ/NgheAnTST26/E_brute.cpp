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

int n;
int h[N];

ll pre[N], f[N];
int l[N];

void Init()
{
    vector<int> st;

    h[0] = oo;
    FORD(i, n, 0)
    {
        while (!st.empty() && h[i] > h[st.back()])
        {
            l[st.back()] = i;
            st.pop_back();
        }
        st.push_back(i);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> h[i], pre[i] = pre[i - 1] + h[i];

    Init();
    FOR(i, 1, n) f[i] = f[l[i]] + 1LL * h[i] * (i - l[i]) - pre[i] + pre[l[i]];
    
    int q, k;
    cin >> q >> k;

    while (q--)
    {
        int w; cin >> w;
        cout << lower_bound(f + 1, f + n + 1, w) - f - 1 << ' ';
    }

    return 0;
}