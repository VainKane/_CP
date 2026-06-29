#ifndef LOCALONLY
#include "ones.h"
#endif // LOCALONLY

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

mt19937_64 rd(time(0));
ll Rand(ll l, ll r) { return l + rd() * 1LL * rd() % (r - l + 1); }

#ifdef LOCALONLY
ii find_longest_subarray_of_ones(int _n);

struct Jury
{
    int n;
    vector<int> a;
    ll num_queries;

    void Init()
    {
        cin >> n;
        a.assign(n, 0);
        REP(i, n) cin >> a[i];
        num_queries = 0;
    }

    int longest_seq_of_1s(){
        int ans = 0, curr = 0;
        for(int i = 0; i < n; ++i){
            if(a[i]){
                ++curr;
            }
            else{
                curr = 0;
            }
            ans = std::max(ans, curr);
        }
        return ans;
    }

    int flip_bits(const std::vector<bool> &flips){
        assert((int)flips.size() == n);
        ++num_queries;
        for(int i = 0; i < n; ++i)
            a[i] = flips[i] ^ a[i];
        return longest_seq_of_1s();
    }

    void Judge()
    {
        ii p = find_longest_subarray_of_ones(n);

        REP(i, n) cerr << a[i] << ' ';
        cerr << '\n' << p.F << ' ' << p.S << '\n';

        assert(p.F <= p.S && p.F >= 0 && p.S < n);
        assert(p.S - p.F + 1 == longest_seq_of_1s());
        FOR(i, p.F, p.S) assert(a[i]);
    }
} jury;

int flip_bits(vector<bool> const &v) { return jury.flip_bits(v); }
#endif // LOCALONLY

int n, len;

void Init()
{
    vector<bool> v(n, 0);
    while (true)
    {
        int lenFlip = flip_bits(vector<bool>(n, 1));
        len = flip_bits(vector<bool>(n, 1));

        if (len > lenFlip) break;
        
        REP(i, n) v[i] = Rand(0, 1);
        len = flip_bits(v);
    }
}

bool Check(int idx)
{
    vector<bool> v(n, 0);
    FOR(i, 0, idx) v[i] = 1;

    int k = flip_bits(v);
    
    REP(i, idx) v[i] = 0;
    v[idx] = 1;
    mini(k, flip_bits(v));

    REP(i, idx) v[i] = 1;
    v[idx] = 0;
    flip_bits(v);

    return k == len;
}

ii find_longest_subarray_of_ones(int _n)
{
    n = _n;

    Init();

    int l = 0, r = n - 1;
    int res = -1;

    while (l <= r)
    {
        int mid = l + r >> 1;
        if (Check(mid)) res = mid, l = mid + 1;
        else r = mid - 1;
    }

    return {res + 1, res + len};
}

#ifdef LOCALONLY
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--)
    {
        jury.Init();
        jury.Judge();
    }

    return 0;
}
#endif // LOCALONLY