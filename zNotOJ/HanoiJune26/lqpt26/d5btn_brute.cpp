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

int const N = 36;

int n, k;
int s[N];

vector<int> pos;
string b = "([{)]}";

int res = 0;

bool Check()
{
    stack<int> st;
    FOR(i, 1, n)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') st.push(s[i]);
        else if (st.empty() || s[i] - st.top() != 1) return false;
    }

    return st.empty();
}

void Try(int idx)
{
    if (idx > sz(pos))
    {
        res += Check();
        return;
    }

    int delta = (idx & 1) ? 3 : 0;
    REP(i, 3) s[idx] = b[i + delta], Try(idx + 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    FOR(i, 1, n)
    {
        cin >> s[i];
        if (s[i] == '?') pos.push_back(i);
    }

    Try(1);
    cout << res;

    return 0;
}