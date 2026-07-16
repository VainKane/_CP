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

int n;

int a[3][N];
int cnt[3][N];

vector<int> pos[N];
bool del[N];

void BFS()
{
    queue<int> q;

    FOR(j, 1, 2) FOR(i, 1, n) if (!cnt[j][i]) 
    {
        for (auto &id : pos[i]) if (!del[id])
        {
            del[id] = true;
            q.push(id);
        }
    }

    while (!q.empty())
    {
        int i = q.front();
        q.pop();

        REP(j, 3) 
        {
            if (--cnt[j][a[j][i]]) continue;
            for (auto &id : pos[a[j][i]]) if (!del[id]) 
            {
                del[id] = true;
                q.push(id);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    REP(j, 3) FOR(i, 1, n) 
    {
        cin >> a[j][i], cnt[j][a[j][i]]++;
        pos[a[j][i]].push_back(i);
    }

    BFS();

    int res = 0;
    FOR(i, 1, n) res += del[i];
    cout << res;

    return 0;
}