#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define all(v) v.begin(), v.end()
#define F first
#define S second
#define name "TREASURE"

int const N = 2009;

int n, k;

pair<int, int> c[N];

bool removed[N];
bool used[N];

vector<pair<int, int>> vals[N];

long long Cal()
{
    memset(used, false, sizeof used);
    long long res = 0;

    FOR(i, 1, n) for (auto p : vals[c[i].S])
    {
        int idx = p.S;
        if (used[idx] || removed[idx]) continue;
        {
            res += p.F;
            used[idx] = true;
            break;
        }
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> k;
    FOR(i, 1, n) 
    {
        int x; cin >> x;
        c[i] = {x, i};    
    }
    FOR(i, 1, k)
    {
        int a, b;
        cin >> a >> b;
        vals[a].push_back({c[b].F, b});
        vals[b].push_back({c[a].F, a});
    }

    FOR(i, 1, n) sort(all(vals[i]), greater<pair<int, int>> ());
    sort(c + 1, c + n + 1, greater<pair<int, int>> ());

    FOR(i, 1, k)
    {
        int p; cin >> p;
        removed[p] = true;
        
        cout << Cal() << '\n';
    }

    return 0;
}