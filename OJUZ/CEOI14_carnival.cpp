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
#define name "CEOI14_carnival"

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

#ifdef LOCALONLY
struct Jury
{
    static int const N = 167;
    // static int const QRLIM = 3500;
    int QRLIM;
    
    int n;
    int a[N];
    bool mark[N];

    int cnt = 0;

    void Init(int _n = 0)
    {
        n = _n;
        QRLIM = n * 24;
        FOR(i, 1, n) cin >> a[i];
    }

    int Query(vector<int> v)
    {
        assert(++cnt <= QRLIM);
        for (auto & i : v) assert(i >= 1 && i <= n);

        int res = 0;

        for (auto &i : v) if (!mark[a[i]])
        {
            mark[a[i]] = true;
            res++;
        }

        for (auto &i : v) mark[a[i]] = false;
        return res;
    }

    void Answer(int res[])
    {
        FOR(i, 1, n) FOR(j, 1, i - 1)
            assert((a[i] == a[j]) == (res[i] == res[j]));
    }
} jury;
#endif // LOCALONLY

int const N = 167;
int const BK = 12;
int const GR = N / BK + 5;

int bkId[N], bkL[N], bkR[N];
int sz[GR];

int n;
int c[N];
int cnt = 0;

void Init()
{
    FOR(i, 1, n)
    {
        int id = bkId[i] = (i - 1) / BK + 1;
        if (!bkL[id]) bkL[id] = i;
        bkR[id] = i;
    }
}

int Query(vector<int> v)
{
    #ifdef LOCALONLY
    return jury.Query(v);
    #endif // LOCALONLY

    cout << sz(v) << ' ';
    for (auto &x : v) cout << x << ' ';
    cout << '\n' << flush;

    int res; cin >> res;
    if (res == -1) exit(0);

    return res;
}

void Answer()
{
    #ifdef LOCALONLY
    return jury.Answer(c);
    #endif // LOCALONLY

    cout << "0 ";
    FOR(i, 1, n) cout << c[i] << ' ';
    cout << '\n' << flush;
}

int Find(int l, int r, int pos)
{
    if (l > r) return 0;
    if (bkId[l] == bkId[r])
    {
        FOR(i, l, r) if (Query({i, pos}) == 1) return i;
        return 0;
    }

    FOR(id, 1, bkId[r] - 1)
    {
        vector<int> v = {pos};
        FOR(i, bkL[id], bkR[id]) v.push_back(i);
        if (Query(v) == sz[id]) return Find(bkL[id], bkR[id], pos);
    }

    return Find(bkL[bkId[r]], r, pos);
}

bool Check(int l, int r, int pos)
{
    FOR(i, l, r) if (c[i] == c[pos]) return false;
    return true;
}

int main()
{
    #ifdef LOCALONLY
    freopen(name".inp", "r", stdin);
    #endif // LOCALONLY

    cin >> n;
    Init();

    #ifdef LOCALONLY
    jury.Init(n);
    #endif // LOCALONLY

    FOR(i, 1, n)
    {
        int pos = Find(1, i - 1, i);
        c[i] = pos ? c[pos] : ++cnt;

        int id = bkId[i];
        sz[id] += Check(bkL[id], i - 1, i);
    }

    Answer();

    return 0;
}