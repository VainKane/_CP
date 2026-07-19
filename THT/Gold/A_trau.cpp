
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
#define ff first
#define ss second
#define pb push_back
#define sp ' '
#define endl '\n'
#define TASKNAME "TASKNAMEGOESHERE"

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
using mii = map<int, int>;
using mll = map<long long, long long>;
using vi2d = vector<vector<int>>;

template<typename T> bool mini(T &a, const T &b) {
     return a > b ? a = b, 1 : 0;
}

template<typename T> bool maxi(T &a, const T &b) {
     return a < b ? a = b, 1 : 0;
}

int const N = 1e4 + 5;
int const BASE = MK(14);
int const NMOD = 2;
int const MODS[] = {(int)1e9 + 2277, (int)1e9 + 5277};

struct Hash
{
    int x[NMOD];

    Hash()
    {
        memset(x, 0, sizeof x);
    }

    bool operator < (Hash const other) const
    {
        REP(k, NMOD) if (x[k] != other.x[k]) return x[k] < other.x[k];
        return false;
    }

    bool operator == (Hash const other) const
    {
        REP(k, NMOD) if (x[k] != other.x[k]) return false;
        return true;
    }
};

int n, k;
long long s;

namespace Sub1
{
    bool CheckSub()
    {
        return k <= 2;
    }

    void Process()
    {
        long long sum = 0;

        FORD(i, n, 1) if (sum + i <= s)
        {
            cout << i << ' ';
            sum += i;
        }

        cout << "0\n";

        if (k == 2)
        {
            sum = 0;
            FOR(i, 1, n) if (sum + i <= s)
            {
                cout << i << ' ';
                sum += i;
            }

            cout << "0\n";
        }
    }
}

namespace TrickLord
{
    bool CheckSub()
    {
        return true;
    }

    int a[N];
    set<Hash> visited;

    int pw[NMOD][N];
    bool mark[N];

    void Init()
    {
        REP(k, NMOD)
        {
            pw[k][0] = 1;
            FOR(i, 1, n) pw[k][i] = 1LL * pw[k][i - 1] * BASE % MODS[k];
        }
    }

    Hash GetHash(vector<int> &v)
    {
        Hash res;

        REP(k, NMOD)
        {
            int tmp = 0;
            REP(i, sz(v)) tmp = (tmp + 1LL * pw[k][i - 1] * v[i]) % MODS[k];
            res.x[k] = tmp;
        }

        return res;
    }

    void Process()
    {
        FOR(i, 1, n) a[i] = i;
        Init();

        while (sz(visited) < k)
        {
            shuffle(a + 1, a + n + 1, mt19937_64(time(0)));
            long long sum = 0;
            FOR(i, 1, n) if (sum + a[i] <= s)
            {
                mark[a[i]] = true;
                sum += a[i];
            }

            vector<int> v;
            FOR(i, 1, n) if (mark[i])
            {
                v.push_back(i);
                mark[i] = false;
            }

            Hash hs = GetHash(v);
            if (sum == s && !visited.count(hs))
            {
                for (auto &x : v) cout << x << ' ';
                cout << "0\n";
                visited.insert(hs);
            }
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k >> s;

//    if (Sub1::CheckSub()) return Sub1::Process(), 0;
    if (TrickLord::CheckSub()) return TrickLord::Process(), 0;

    return 0;
}
