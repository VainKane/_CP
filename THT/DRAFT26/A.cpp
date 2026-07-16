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

ll n;

string ToString(__int128 x)
{
    string digits = "";

    while (x)
    {
        digits += x % 10 + '0';
        x /=  10;
    }

    reverse(all(digits));
    return digits;
}

namespace sub1 {
    const int maxn = 1005;
    bool check() { return n < maxn; }
    int a[maxn][maxn];
    void solve() {
        FOR(i, 1, n) FOR(j, 1, n) a[i][j] = (i - 1) * n + j;
        if (n & 1) {
            int mid = n / 2 + 1;
            cout << a[mid][mid] << endl;
        } else {
            int mid = n / 2;
            cout << a[mid][mid] + a[mid][mid + 1] + a[mid + 1][mid] + a[mid + 1][mid + 1] << endl;
        }
    }
}

void solve() {
    if (n & 1) {
        __int128 mid = n / 2 + 1;
        cout << ToString((mid - 1) * n + mid) << endl;
    } else {
        __int128 mid = n / 2;
        auto get = [](__int128 i, __int128 j) {
            return (i - 1) * n + j;
        };
        cout << ToString(get(mid, mid) + get(mid, mid + 1) + get(mid + 1, mid) + get(mid + 1, mid + 1));
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
//    if (sub1::check()) return sub1::solve(), 0;
    return solve(), 0;
    return 0;
}
