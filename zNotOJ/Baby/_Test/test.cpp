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

int cnt = 0;

long long GCD(long long a, long long b)
{
    if (a == 0 || b == 0 || a == b) return a | b;
    if (a > b) a %= b; else b %= a;
}

int a[1000] = {0, 1, 2, 3};

int Fibo(int n)
{
    if (n <= 2) return 1;
    return Fibo(n - 1) + Fibo(n - 2);
}

int Count(int x)
{
    int cnt = 0;
    FOR(i, 2, x) if (x % i == 0) cnt++;
    return cnt;
}

int main()
{
    int res = 0;
    FOR(i, 2, 1e4) maxi(res, Count(i));
    cout << res << '\n';
    // GCD(1e18, 4352345234231234);
    // cout << cnt;

    // int n; cin >> n;

    // for (int i = 1; i <= n; i++) a[i] = i;

    // do
    // {
    //     for (int i = 1; i <= n; i++) cout << a[i] << ' ';
    //     cout << '\n';
    // } while (next_permutation(a + 1, a + n + 1));

    // string s = "abcde";
    // s.resize(s.size() - 1);
    // cout << s;

    // priority_queue<int> pq;
    // pq.push(2);
    // pq.push(2);
    // pq.push(2);

    // // cout << pq.size();

    // cout << (long long)10e18;

    // REP(i, Fibo(32)) cout << i << ' ';

    // vector<int> vt = {1, 2, 3, 4};

    // int a = (1 << 0) - 1;
    // cout << a;

    // cout << -123 % 5;

    // cout << char(67);

    // vector<pair<int, int>> res;
    // cout << res[0].first << ' ' << res[0].second;

    // cout << (int)'␡';

    // int a;
    // scanf("%c", &a);
    // cout << a;

    // long long d[3];
    // memset(d, 0x3f, sizeof d);
    // cout << d[0] << '\n' << (long long)1e18;

    // int n; cin >> n;

    // int tmp = 0, res = 0;

    // for (int i = 1; i <= n; i++)
    // {
    //     int x; cin >> x;
    //     tmp += x;
    //     res += tmp;
    // }

    // cout << res;

    // cout << (int)'(' << ' ' << (int)')';

    // int x = 9;
    // assert(x == 7);

    // freopen("blabla.out", "w", stdout);
    // // cout << (char)32;

    // int n;
    // cin >> n;

    // FOR(i, 1, n) cin >> a[i];
    // sort(a + 1, a + n + 1);

    // FOR(i, 1, n) cout << a[i] << '\n';

    // cout << (long long)1e11 - 1;
//    cout << (int)'.';

    #ifdef LOCALONLY
    cout << "gold medalist\n";
    #endif //LOCALONLY
}
