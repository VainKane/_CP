#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b ; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define all(v) v.begin(), v.end()
#define F first
#define S second
#define name "bracket"

int const N = 1e6 + 5;
int const MOD = 1e9 + 19972207;

int n, m;

int openId[N], closeId[N];
int p[2 * N], inv[2 * N];

vector<int> children[N];

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

int Catalan(int n)
{
    int res = 1ll * p[2 * n] * inv[n + 1] % MOD;
    return 1ll * res * inv[n] % MOD;
}

void Init()
{
    p[0] = 1;
    FOR(i, 1, 2 * n) p[i] = 1ll * p[i - 1] * i % MOD;

    inv[2 * n] = PowMod(p[2 * n], MOD - 2);
    FORD(i, 2 * n - 1, 0) inv[i] = 1ll * (i + 1) * inv[i + 1] % MOD;
}

void PrintZero()
{
    cout << 0;
    exit(0);
}

int DFS(int u)
{
    int res = 1;
    int len = closeId[u] - u - 1;

    for (auto v : children[u])
    {
        len -= closeId[v] - v + 1;
        res = 1ll * res * DFS(v) % MOD;
    }

    if (len & 1) PrintZero();
    return 1ll * res * Catalan(len / 2) % MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> m;
    FOR(i, 1, m)
    {
        int x, y;
        cin >> x >> y;

        if ((y - x + 1) & 1) PrintZero();
        if (openId[y] && x != openId[y]) PrintZero();
        if (closeId[x] && y != closeId[x]) PrintZero();
        if (closeId[y] || openId[x]) PrintZero();

        closeId[x] = y;
        openId[y] = x;
    }

    Init();

    openId[n + 1] = 0;
    closeId[0] = n + 1; 

    stack<int> st;
    FOR(i, 0, n + 1)
    {
        if (closeId[i]) st.push(i);
        else if (openId[i])
        {
            if (openId[i] != st.top()) PrintZero();
            st.pop();
            children[st.top()].push_back(openId[i]);
        }
    }

    cout << DFS(0);

    return 0;
}