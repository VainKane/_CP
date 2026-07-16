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

int Query(int idx)
{
    cout << "? " << idx << '\n' << flush;
    int res; cin >> res;

    if (res == -1) exit(0);
    return res;
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
    int l = 1, r = n - 1;
    int res = 0;

    while (l <= r)
    {
        int mid = l + r >> 1;

        if (Query(mid) > Query(mid + 1))
        {
            res = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }

    Answer(res + 1);

    return 0;
}