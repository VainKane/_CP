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

int const N = 1e5 + 5;

int n, m;
bool online;

int a[N];
vector<pair<int, int>> qr[N];

pair<int, int> GetSegment(int l, int r, int &prev)
{
    l = (l ^ prev) % n + 1;
    r = (r ^ prev) % n + 1;
    if (l > r) swap(l, r);

    return {l, r};
}

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.F != b.F) return a.F < b.F;
    return a.S > b.S;
}

namespace Sub2
{
    bool CheckSub()
    {
        return n <= 5000 && m <= 5000;
    }

    void Process()
    {
        int prevAns = 0;
        FOR(id, 1, m)
        {
            int k = sz(qr[id]);
            if (online && id > 1) REP(i, k) qr[id][i] = GetSegment(qr[id][i].F, qr[id][i].S, prevAns);
            sort(all(qr[id]), cmp);

            int maxR = 0;
            int idx = 0;

            vector<int> v;

            FOR(i, 1, n)
            {
                for (; idx < k && qr[id][idx].F <= i; idx++) maxi(maxR, qr[id][idx].S);
                if (i <= maxR) v.push_back(a[i]);
            }

            sort(all(v));
            v.erase(unique(all(v)), v.end());
            prevAns = sz(v);

            cout << sz(v) << '\n';
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> online;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, m)
    {
        int k; cin >> k;
        while(k--)
        {
           int l, r;
           cin >> l >> r;
           qr[i].push_back({l, r});
        }
    }

    if (Sub2::CheckSub()) return Sub2::Process(), 0;

    return 0;
}
