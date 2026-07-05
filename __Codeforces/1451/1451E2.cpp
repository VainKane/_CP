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

int const N = MK(16) + 5;

int n;
int a[N], b[N];
int lst[N];

int Query(string qr, int i, int j)
{
    cout << qr << ' ' << i << ' ' << j << '\n' << flush;
    int res; cin >> res;

    if (res == -1) exit(0);
    return res;
}

void Answer()
{
    cout << "! ";
    FOR(i, 1, n) cout << a[i] << ' ';
    cout << '\n' << flush;
    exit(0);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    pair<int, int> haha = {0, 0};
    lst[0] = 1;

    FOR(i, 2, n)
    {
        b[i] = Query("XOR", 1, i);
        if (lst[b[i]]) haha = {lst[b[i]], i};
        lst[b[i]] = i;
    }

    if (haha.F == 0)
    {
        FOR(i, 2, n) if (b[i] == n - 1)
        {
            int j = i == n ? n - 1 : n;
            int s23 = (b[j] ^ b[i]) + 2 * Query("AND", j, i);

            a[1] = b[j] + 2 * Query("AND", 1, j) + n - 1 - s23;
            a[1] >>= 1;
            break;
        }
    }
    else
    {
        int idx = haha.F;
        a[idx] = Query("AND", haha.F, haha.S);
        a[1] = a[idx] ^ b[idx];
    }

    FOR(i, 2, n) a[i] = a[1] ^ b[i];
    Answer();

    return 0;
}