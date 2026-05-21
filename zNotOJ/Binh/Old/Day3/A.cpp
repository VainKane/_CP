#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

struct Person
{
    int a, c, x;

    bool operator < (Person const other) const
    {
        return x > other.x;
    }
};

int const N = 2009;

int n, A, C;

Person p[N];
int dp[2][2 * N];

int cur = 0, pre = 1;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> A >> C;
    FOR(i, 1, n)
    {
        int a, c, x;
        cin >> a >> c >> x;
        p[i] = {a, c, x};
    }

    sort(p + 1, p + n + 1);
    
    FOR(i, 1, n) 
    {
        swap(cur, pre);

        FOR(j, 0, A + C)
        {
            dp[cur][j] = dp[pre][j];

            int numCake = min(max(0, j - A), p[i].c * p[i].x);
            int numMoney = p[i].c - numCake / p[i].x;

            if (numMoney <= min(j, A)) maxi(dp[cur][j], dp[pre][j - (numCake + numMoney)] + p[i].a);
        }
    }

    cout << dp[cur][A + C];

    return 0;
}