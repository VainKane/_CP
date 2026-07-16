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

int n;

int Query(int l, int r)
{
    if (l >= r) return 0;

    cout << "? " << l << ' ' << r << '\n' << flush;
    int idx; cin >> idx;

    if (idx == -1) exit(0);
    return idx;
}

void Answer(int idx)
{
    cout << "! " << idx << '\n' << flush;
    exit(0);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    int idx = Query(1, n);
    int delta = Query(1, idx) == idx ? -1 : 1;

    int l = 1, r = delta == -1 ? idx - 1 : n - idx;
    int res = r;

    while (l <= r)
    {
        int mid = l + r >> 1;

        int u = idx, v = idx + delta * mid;
        if (u > v) swap(u, v);

        if (Query(u, v) == idx)
        {
            res = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }

    Answer(idx + delta * res);

    return 0;
}