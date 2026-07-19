#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define BIT(i, x) (((x) >> (i)) & 1)
#define MK(i) (1LL << (i))
#define ALL(v) v.begin(), v.end()
#define sz(v) ((int)v.size())
#define F first
#define S second
#define name "TET"

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 509;

int n, q, pos;
int a[N];

vector<vector<int>> seq1, seq2;

void SwapSeg(int l, int r)
{
    for (int len = 0; l + len < r - len; len++) swap(a[l + len], a[r - len]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> q;
    FOR(i, 1, n) cin >> a[i];
    cin >> pos;

    FOR(i, 1, pos - 1)
    {
        FOR(j, i, pos - 1)
        {
            SwapSeg(i, j);

            vector<int> v;
            FOR(idx, 1, pos - 1) v.push_back(a[idx]);
            seq1.push_back(v);

            SwapSeg(i, j);
        }
    }

    FOR(i, pos + 1, n)
    {
        vector<int> v;
        FOR(j, pos + 1, n)
        {
            SwapSeg(i, j);

            vector<int> v;
            FOR(idx, pos + 1, n) v.push_back(a[idx]);
            seq2.push_back(v);

            SwapSeg(i, j);
        }
    }

    sort(ALL(seq1));
    sort(ALL(seq2));

    seq1.erase(unique(ALL(seq1)), seq1.end());
    seq2.erase(unique(ALL(seq2)), seq2.end());

    cout << max(sz(seq1), sz(seq2));

    return 0;
}
