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

int const N = 36;
long long const oo = 1e18;

int n;
int a[N];

vector<long long> s1, s2;
long long s = 0;

map<long long, int> mp;

void Build(int st, int n, vector<long long> &s)
{
    REP(mask, MK(n))
    {
        long long sum = 0;
        for (int tmp = mask; tmp; tmp ^= tmp & -tmp)
        {
            int i = __builtin_ctz(tmp);
            sum += a[st + i];
        }

        s.push_back(sum);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    REP(i, n) cin >> a[i], s += a[i];

    int n1 = n / 2, n2 = n - n1;
    Build(0, n1, s1);
    Build(n1, n2, s2);

    sort(all(s1)); sort(all(s2));
    long long res = oo;
    
    for (auto &x : s2)
    {
        int idx = lower_bound(all(s1), (s - 2 * x + 1) >> 1LL) - s1.begin();
        if (idx < sz(s1)) mini(res, abs(2 * (x + s1[idx]) - s));

        idx = upper_bound(all(s1), (s - 2 * x) >> 1LL) - s1.begin();
        mini(res, abs(2 * (x + s1[idx - 1]) - s));
    }

    long long cnt = 0;
    for (auto &x : s1) mp[2 * x]++;
    for (auto &x : s2)
    {
        auto it = mp.find(res + s - 2 * x);
        if (it != mp.end()) cnt += it->S;

        if (res == 0) continue;
        it = mp.find(-res + s - 2 * x);
        if (it != mp.end()) cnt += it->S;
    }

    cout << res << ' ' << cnt / 2;
    
    return 0;
}