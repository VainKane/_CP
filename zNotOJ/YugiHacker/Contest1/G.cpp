#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define MK(i) (1ll << (i))
#define F first
#define S second

int const N = 2e5 + 5;
int const LOG = 18;

int n, q;
int a[N], b[N];

map<int, int> mp;
int pre[N];

int lg[N];

int upMin[N][20];
int upMax[N][20];
int upPre[N][20];
int upGCD[N][20];

int GCD(int a, int b)
{
    a = abs(a); b = abs(b);

    while (true)
    {
        if (a == 0 || b == 0 || a == b) return a | b;
        if (a > b) a %= b; else b %= a;
    }
}

void Init()
{
    FOR(i, 1, n) 
    {
        upMin[i][0] = upMax[i][0] = a[i];
        upPre[i][0] = pre[i];
        upGCD[i][0] = b[i];
    }

    FOR(j, 1, LOG) FOR(i, 1, n - MK(j) + 1)
    {
        upMin[i][j] = min(upMin[i][j - 1], upMin[i + MK(j - 1)][j - 1]);
        upMax[i][j] = max(upMax[i][j - 1], upMax[i + MK(j - 1)][j - 1]);
        upPre[i][j] = max(upPre[i][j - 1], upPre[i + MK(j - 1)][j - 1]);
        upGCD[i][j] = GCD(upGCD[i][j - 1], upGCD[i + MK(j - 1)][j - 1]);
    }

    FOR(i, 2, n) lg[i] = lg[i / 2] + 1;
}

pair<int, int> GetMinMax(int l, int r)
{
    int k = lg[r - l + 1];
    return {min(upMin[l][k], upMin[r - MK(k) + 1][k]), 
            max(upMax[l][k], upMax[r - MK(k) + 1][k])};
}

int GetMaxPre(int l, int r)
{
    int k = lg[r - l + 1];
    return max(upPre[l][k], upPre[r - MK(k) + 1][k]);
}

int GetGCD(int l, int r)
{
    int k = lg[r - l + 1];
    return GCD(upGCD[l][k], upGCD[r - MK(k) + 1][k]);
}

bool Check(int l, int r)
{
    pair<int, int> p = GetMinMax(l, r);

    if (p.F == p.S) return true;
    if ((p.S - p.F) % (r - l) != 0) return false;
    if (GetMaxPre(l, r) >= l) return false;
    return GetGCD(l, r - 1) == (p.S - p.F) / (r - l);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("G.inp", "r", stdin);
    // freopen("G.out", "w", stdout);

    cin >> n >> q;
    FOR(i, 1, n) 
    {
        cin >> a[i];
        
        int &x = mp[a[i]];
        pre[i] = x;
        x = i;

        b[i - 1] = a[i] - a[i - 1];
    }

    Init();

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << (Check(l, r) ? "YES\n" : "NO\n");
    }

    return 0;
}