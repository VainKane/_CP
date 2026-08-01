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

int n, k, s;
mt19937_64 rd(time(0));

long long Rand(long long l, long long r)
{
    return l + rd() * 1LL * rd() % (r - l + 1);
}

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
            FORD(i, n - 1, 1) if (sum + i <= s)
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
    long long randVal[N];
    set<long long> visited;

    void Process()
    {
        FOR(i, 1, n)
        {
            randVal[i] = Rand(1, 1e18);
            a[i] = i;
        }

        while (sz(visited) < k)
        {
            shuffle(a + 1, a + 5 + 1, mt19937_64(time(0)));
            long long sum = 0;

            vector<int> v;
            long long hs = 0;

            FOR(i, 1, n) if (sum + a[i] <= s)
            {
                hs ^= randVal[a[i]];
                v.push_back(a[i]);
                sum += a[i];
            }

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

    // if (Sub1::CheckSub()) return Sub1::Process(), 0;
    if (TrickLord::CheckSub()) return TrickLord::Process(), 0;

    return 0;
}