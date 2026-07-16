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

int const N = 5009;

int n;
int a[N];

int Query(int i, int j)
{
    cout << "? " << i << ' ' << j << '\n' << flush;
    int res; cin >> res;
    if (res == -1) exit(0);
    return res;
}

void Answer()
{
    cout << "! ";
    FOR(i, 1, n) cout << a[i] << ' ';
    cout << '\n' << flush;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    
    int s1 = Query(1, 2);
    int s2 = Query(2, 3);
    int s3 = Query(1, 3);

    a[1] = (s1 - s2 + s3) / 2;
    a[2] = s1 - a[1];
    a[3] = s3 - a[1];

    FOR(i, 4, n) a[i] = Query(1, i) - a[1];

    Answer();

    return 0;
}