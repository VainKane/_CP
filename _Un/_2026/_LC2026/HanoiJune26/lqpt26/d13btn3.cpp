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

int const N = 1e5 + 5;

int n, x, y, z;
vector<int> a[N];

ll val1[N], val2[N];
bool cmp(vector<int> a, vector<int> b) { return a[1] - a[2] > b[1] - b[2]; }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> x >> y >> z;

    FOR(i, 1, 1e5) a[i] = vector<int> (4, 0);

    int haha = 1;
    while (cin >> a[haha][1] >> a[haha][2] >> a[haha][3]) haha++;
    n = haha - 1;

    sort(a + 1, a + n + 1, cmp);
    priority_queue<int, vector<int>, greater<int>> pq;
    ll tmp = 0, sum = 0;

    FOR(i, 1, n)
    {
        pq.push({a[i][1] - a[i][3]});
        tmp += a[i][1] - a[i][3];
        sum += a[i][3];

        while (sz(pq) > x)
        {
            tmp -= pq.top();
            pq.pop();
        }

        val1[i] = tmp + sum;
    }

    pq = priority_queue<int, vector<int>, greater<int>>();
    tmp = sum = 0;

    FORD(i, n, 1)
    {
        pq.push({a[i][2] - a[i][3]});
        tmp += a[i][2] - a[i][3];
        sum += a[i][3];

        while (sz(pq) > y)
        {
            tmp -= pq.top();
            pq.pop();
        }

        val2[i] = tmp + sum;
    }

    ll res = 0;
    FOR(i, x, n - y) maxi(res, val1[i] + val2[i + 1]);
    cout << res;

    return 0;
}