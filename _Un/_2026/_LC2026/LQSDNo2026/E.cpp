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

int const N = 2e6 + 5;

int n, k;
ll s;

int w[N], c[N];
vector<int> res;

void DNC(int l, int r, int b, int mask, vector<int> v)
{
    if (b < 0)
    {
        FOR(i, l, r) res[i - 1] = mask;
        return;
    }

    bool ok = false;
    
    ll sum = 0;
    int j = 0;

    while (j < sz(v) && v[j] < l)
    {
        sum += !BIT(b, w[v[j]]) * c[v[j]];
        j++;
    }
    
    FOR(i, l, r)
    {
        if (j < sz(v) && v[j] <= i)
        {
            sum += !BIT(b, w[v[j]]) * c[v[j]];
            j++;
        }

        if (sum >= s)
        {
            vector<int> tmp1, tmp2;
            for (auto &j : v)
            {
                if (j >= i) break;
                tmp1.push_back(j);
            }

            for (auto &j : v)
            {
                if (j > r) break;
                if (!BIT(b, w[j])) tmp2.push_back(j);
            }

            DNC(l, i - 1, b - 1, mask | MK(b), tmp1);
            DNC(i, r, b - 1, mask, tmp2);
            ok = true;
            break;
        }
    }

    if (!ok) DNC(l, r, b - 1, mask | MK(b), v);
}

vector<int> solve(int _n, int _k, ll _s, vector<int> const &_w, vector<int> const &_c)
{
    n = _n, k = _k, s = _s;
    FOR(i, 1, n) w[i] = _w[i - 1], c[i] = _c[i - 1];

    res = vector<int>(n);
    vector<int> tmp;
    FOR(i, 1, n) tmp.push_back(i);

    DNC(1, n, k, 0, tmp);
    REP(i, n) if (res[i] >= MK(k)) res[i] = -1;

    return res;
}

#ifdef LOCALONLY
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, k, s;
    vector<int> w, c;

    cin >> n >> k >> s;
    w = c = vector<int>(n);

    REP(i, n) cin >> w[i];
    REP(i, n) cin >> c[i];

    vector<int> res = solve(n, k, s, w, c);
    for (auto &x : res) cout << x << ' ';

    return 0;
}
#endif