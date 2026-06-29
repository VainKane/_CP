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

bool Check(int l, int r, int mid)
{
    int id = Query(l, r);
    if (id <= mid) return Query(l, mid) == id;
    return Query(mid + 1, r) != id;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    int l = 1, r = n;

    while (r - l > 1)
    {
        int mid = l + r >> 1;
        if (Check(l, r, mid)) r = mid;
        else l = mid;
    }

    Answer(Query(l, r) ^ l ^ r);

    return 0;
}