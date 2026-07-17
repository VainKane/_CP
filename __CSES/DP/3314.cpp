#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define BIT(i, x) (((x) >> (i)) & 1)
#define MK(i) (1ll << (i))
#define all(v) v.begin(), v.end()
#define sz(v) ((int)v.size())
#define F first
#define S second

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 2e5 + 5;
int const oo = 1e9 + 9;

int n;

int a[N];
int l[N], r[N];

void Init()
{
    stack<int> st;

    a[n + 1] = oo;
    FOR(i, 1, n)
    {
        while (!st.empty() && a[i] > a[st.top()])
        {
            r[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }

    while (!st.empty())
    {
        r[st.top()] = n;
        st.pop();
    }

    FORD(i, n, 1)
    {
        while (!st.empty() && a[i] > a[st.top()])
        {
            l[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }

    while (!st.empty())
    {
        l[st.top()] = 1;
        st.pop();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> a[i];

    Init();

    int res = 1;

    FOR(i, 1, n) 
    {
        maxi(res, i - l[i]);
        maxi(res, r[i] - i);
    }

    cout << res;

    return 0;
}