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
#define name "CARDS"

using ll = long long;
using ii = pair<int, int>;

template <class T> bool maxi(T &x, T const &y) { return x < y ? x = y, 1 : 0; }
template <class T> bool mini(T &x, T const &y) { return x > y ? x = y, 1 : 0; }

int const N = 5e6 + 5;

int n;
ll k;

char s[N];
int a[N], b[N];

bool visited[N];
int cnt[256];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> k;
    FOR(i, 1, n) cin >> s[i], cnt[s[i]]++;
    FOR(i, 1, n) cin >> a[i];

    FOR(i, 1, n) if (!visited[i])
    {
        vector<int> v = {i};

        visited[i] = true;
        int pos = i;

        while (!visited[a[pos]])
        {
            pos = a[pos];
            visited[pos] = true;
            v.push_back(pos);
        }

        REP(j, sz(v)) b[v[j]] = v[(j + k) % sz(v)];
    }

    char ch = 'a';
    FOR(i, 1, n)
    {
        while (!cnt[ch]) ch++;
        s[i] = ch, cnt[ch]--;
    }

    FOR(i, 1, n) cout << s[b[i]];
    
    return 0;
}