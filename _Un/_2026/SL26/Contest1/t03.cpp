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

int const N = 1e6 + 5;
 
int n, k;
bool a[N], b[N];
bool lmao[N];

set<int> s[2];

void Input(bool a[])
{
    string s; cin >> s;
    FOR(i, 1, n) a[i] = s[i - 1] - '0';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    Input(a), Input(b);

    FOR(i, 1, n) if (a[i] != b[i]) s[a[i]].insert(i);

    ll res = 0;
    FOR(i, 1, n)
    {
        if (a[i] == b[i]) s[a[i]].erase(i);
        else
        {
            int j = *s[b[i]].begin();
            res += (j - i + k - 1) / k;

            s[b[i]].erase(j);
            s[a[i]].erase(i), s[a[i]].insert(j);
            a[j] ^= 1;
        }
    }

    cout << res;

    return 0;
}