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
#define name "sign"

using ll = long long;
using ii = pair<int, int>;

template <class T> bool maxi(T &x, T const &y) { return x < y ? x = y, 1 : 0; }
template <class T> bool mini(T &x, T const &y) { return x > y ? x = y, 1 : 0; }

mt19937_64 rd(time(0));
ll Rand(ll l, ll r) { return l + rd() * 1LL * rd() % (r - l + 1); }

int const N = 1.5e6;
int const lim = 290;

int k, t;
ll n;

ll pw[N];
int bd[] = {0, (int)1.5e6, (int)1.5e6, (int)1e6, 31622, 3981, 1000, 372, 177, 100};

int m, resM;
bool s[N], resS[N];
ll val, resVal;

int d[] = {-1, 1};
char ds[] = {'-', '+'};

void Init()
{
    val = 0;
    FOR(i, 1, bd[k])
    {
        s[i] = i & 1;
        val += d[s[i]] * pw[i];
        m = i;
        if (val >= n) break;
    }
}

ll Eval(bool s[], int m)
{
    ll res = 0;
    FOR(i, 1, m) res += d[s[i]] * pw[i];
    return res;
}

void Set()
{
    resM = m, resVal = val;
    FOR(i, 1, resM) resS[i] = s[i];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> k >> t;
    FOR(i, 1, bd[k])
    {
        pw[i] = i;
        REP(j, k - 1) pw[i] *= i;
    }

    while (t--)
    {
        cin >> n;

        Init();
        Set();
        resVal = val = Eval(s, m);

        auto startTime = chrono::high_resolution_clock::now();
        while (chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - startTime).count() <= lim)
        {
            // cerr << resM << ' ' << resVal << '\n';
         
            bool opt = false;
            FOR(i, 1, m - 1)
            {
                ll cur = abs(val - n);

                ll delta = -2 * d[s[i]] * pw[i] - 2 * d[s[i + 1]] * pw[i + 1];
                ll nxt = val + delta;

                if (abs(nxt - n) < cur)
                {
                    val += delta;
                    s[i] ^= 1, s[i + 1] ^= 1;
                    opt = true;
                }
            }

            if (abs(val - n) < abs(resVal - n)) Set();
            if (!opt)
            {
                m += Rand(max(-5, -m + 1), 5);
                REP(i, m / 10) s[Rand(1, m)] ^= 1;
                val = Eval(s, m);
            }
        }

        // assert(Eval(resS, resM) == resVal);

        cout << resM << ' ';
        FOR(i, 1, resM) cout << ds[resS[i]];
        if (t) cout << '\n';
    }

    return 0;
}