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

int const N = 2e5 + 5;
int const LOG = 20;

struct Query
{
    int x, y, d;
    void Input() { cin >> x >> y >> d; }
};

int n, q;
vector<int> v[2], h[2];

Query qr[N];
vector<int> vals;

int nxtX[2][LOG][3 * N], nxtV[2][LOG][3 * N];

#define GetId(x) (lower_bound(all(vals), (x)) - vals.begin() + 1)

void Compress()
{
    REP(i, 2)
    {
        vals.insert(vals.end(), all(v[i]));
        vals.insert(vals.end(), all(h[i]));
    }

    FOR(i, 1, q)
    {
        vals.push_back(qr[i].x);
        vals.push_back(qr[i].y);
    }

    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());

    FOR(i, 1, q) qr[i].x = GetId(qr[i].x), qr[i].y = GetId(qr[i].y);
    REP(i, 2)
    {
        for (auto &x : v[i]) x = GetId(x);
        for (auto &x : h[i]) x = GetId(x);
    }
}

void Init()
{
    FOR(i, 1, sz(vals))
    {
        int x = vals[i - 1];
        auto it = lower_bound(all(h[x & 1]), x);
        if (it != h[x & 1].end()) nxtX[0][i] = GetId(*it);

        // it = lower_bound(all(v[j]), x);
        // if (it != v[j].end()) nxtV[i][j] = GetId(*it);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    FOR(i, 1, n)
    {
        char type;
        int val;

        cin >> type >> val;

        if (type == 'V') v[val & 1].push_back(val);
        else h[val & 1].push_back(val);
    }

    FOR(i, 1, q) qr[i].Input();

    REP(i, 2) sort(all(v[i])), sort(all(h[i]));

    Compress();



    return 0;
}