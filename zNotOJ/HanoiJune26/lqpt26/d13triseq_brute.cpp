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

int n;
ll k;

vector<int> a;
vector<vector<int>> v;

void GetNew(int mi1, int mi2, int ma, int x, int &nmi1, int &nmi2, int &nma)
{
    nmi1 = min(x, mi1);
    nmi2 = x <= mi1 ? mi1 : min(x, mi2);
    nma = max(x, ma);
}

void Try(int pos, int mi1, int mi2, int ma, vector<int> seq)
{
    if (pos > n)
    {
        v.push_back(seq);
        return;
    }

    FOR(i, 1, n)
    {
        int nmi1, nmi2, nma;
        GetNew(mi1, mi2, ma, i, nmi1, nmi2, nma);

        if (nmi1 + nmi2 > nma)
        {
            seq.push_back(i);
            Try(pos + 1, nmi1, nmi2, nma, seq);
            seq.pop_back();
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    a.assign(n, 0);
    REP(i, n) cin >> a[i];

    Try(1, n + 1, n + 1, 0, {});

    cout << sz(v) << '\n';
    for (auto &x : v[k - 1]) cout << x << ' ';
    cout << '\n';
    REP(i, sz(v)) if (a == v[i])
    {
        cout << i + 1;        
        break;
    }

    return 0;
}