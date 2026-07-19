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

int const N = 209;

int n, x, y, z;
int a[N], b[N], c[N];

namespace Sub1
{
    bool CheckSub()
    {
        return n <= 20;
    }

    void Process()
    {
        REP(mask, MK(n))
        {
            int s1 = 0, s2 = 0, s3 = 0;
            for (int tmp = mask; tmp; tmp ^= tmp & -tmp)
            {
                int i = __builtin_ctz(tmp);
                s1 += a[i + 1], s2 += b[i + 1], s3 += c[i + 1];
            }

            if (s1 == x && s2 == y && s3 == z)
            {
                REP(i, n) cout << BIT(i, mask);
                return;
            }
        }
    }
}

namespace Sub2
{
    bool CheckSub()
    {
        return n <= 40;
    }

    struct State
    {
        int a, b, c, mask;

        bool operator < (State const other) const
        {
            if (a != other.a) return a < other.a;
            if (b != other.b) return b < other.b;
            return c < other.c;
        }

        bool operator == (State const other) const
        {
            return a == other.a && b == other.b && c == other.c;
        }
    };

    int const M = 1e6 + 5;
    vector<State> masks1, masks2;

    void Build(int st, int n, vector<State> &masks)
    {
        REP(mask, MK(n))
        {
            int s1 = 0, s2 = 0, s3 = 0;
            for (int tmp = mask; tmp; tmp ^= tmp & -tmp)
            {
                int i = __builtin_ctz(tmp);
                s1 += a[i + st + 1], s2 += b[i + st + 1], s3 += c[i + st + 1];
            }

            masks.push_back({s1, s2, s3, mask});
        }
    }

    void Process()
    {
        int n1 = n / 2, n2 = n - n1;
        Build(0, n1, masks1);
        Build(n1, n2, masks2);

        sort(all(masks1));
        for (auto &st : masks2)
        {
            State tar = {x - st.a, y - st.b, z - st.c, 0};
            auto it = lower_bound(all(masks1), tar);
            if (it != masks1.end() && *it == tar)
            {
                REP(i, n1) cout << BIT(i, it->mask);
                REP(i, n2) cout << BIT(i, st.mask);
                return;
            }
        }
    }
}

namespace Sub3
{
    bool CheckSub()
    {
        return true;
        FOR(i, 1, n) if (b[i] || c[i]) return false;
        return true;
    }

    int const M = 1e6 + 5;
    bitset<M> dp[N];
    bool mark[N];

    void Process()
    {
        dp[0][0] = 1;
        FOR(i, 1, n) dp[i] = dp[i - 1] | (dp[i - 1] << a[i]);

        FORD(i, n, 1)
        {
            if (x >= a[i] && dp[i - 1][x - a[i]])
            {
                mark[i] = true;
                x -= a[i];
            }
        }

        FOR(i, 1, n) cout << mark[i];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> x >> y >> z;
    FOR(i, 1, n) cin >> a[i] >> b[i] >> c[i];

    if (Sub1::CheckSub()) return Sub1::Process(), 0;
    if (Sub2::CheckSub()) return Sub2::Process(), 0;
    if (Sub3::CheckSub()) return Sub3::Process(), 0;

    return 0;
}
