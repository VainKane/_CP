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

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 2e5 + 5;

int n, k;
int a[N], b[N];
bool mark[N];

bool Solve()
{
    FOR(l, 1, n)
    {
        if (mark[l])
        {
            int r = l;

            vector<int> v1, v2;
            for (; r <= n && mark[r] == mark[l]; r++)
            {
                v1.push_back(a[r]);
                v2.push_back(b[r]);
            }

            sort(all(v1)), sort(all(v2));
            if (v1 != v2) return false;

            l = r - 1;
        }
        else if (a[l] != b[l]) return false;
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--)
    {
        cin >> n >> k;
        FOR(i, 1, n) cin >> a[i];
        FOR(i, 1, n) cin >> b[i];

        memset(mark, false, (n + 1) * sizeof(bool));
        FOR(i, 1, n - 1) if (a[i] + a[i + 1] == k || a[i] == a[i + 1]) mark[i] = mark[i + 1] = true;
        cout << (Solve() ? "YES\n" : "NO\n");
    }

    return 0;
}