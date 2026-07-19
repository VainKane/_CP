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

long long a, b;

bool Check(long long x)
{
    FOR(i, 2, sqrt(x)) if (x % i == 0) return false;
    return x > 1;
}

void BFS()
{
    queue<long long> q;
    FOR(i, 2, 7) if (Check(i)) q.push(i);

    int res = 0;

    while (!q.empty())
    {
        long long x = q.front();
        q.pop();

        res += max(11LL, a) <= x && x <= b;

        FOR(d, 0, 9)
        {
            long long y = x * 10 + d;
            if (Check(y)) q.push(y);
        }
    }

    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> a >> b;
    BFS();

    return 0;
}