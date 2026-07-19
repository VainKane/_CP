#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define sz(v) ((int)v.size())
#define F first
#define S second

int dx[] = {0, 0, 1, 1, 0, -1, -1};
int dy[] = {0, 1, 0, -1, -1, 0, 1};

int const MOD = 1e9 + 7;

int n;
int b = 0;
long long x = 0, y = 0;

vector<pair<long long, long long>> v = {{0, 0}};

void Add(int &x, int const &y)
{
    x += y;
    if (x >= MOD) x -= MOD;
}

int PowMod(int a, int b)
{
    int res = 1;

    while (b)
    {
        if (b & 1) res = 1ll * res * a % MOD;
        b >>= 1;
        a = 1ll * a * a % MOD;
    }

    return res;
}

int Area()
{
    long long res = 0;
    FOR(i, 1, sz(v) - 1) res += (v[i].F - v[i - 1].F) * (v[i].S + v[i - 1].S);
    return abs(res) % MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n)
    {
        int dir, k;
        cin >> dir >> k;

        x += dx[dir] * k;
        y += dy[dir] * k;
        v.push_back({x, y});
        Add(b, k);
    }

    int inv2 = PowMod(2, MOD - 2);
    // cout << (1ll * Area() * inv2 - 1ll * b * inv2 + 1 + MOD) % MOD;

    cout << Area();
    // for (auto &p : v) cout << p.F << ' ' << p.S << '\n';

    return 0;
}