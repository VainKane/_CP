#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define sz(v) ((int)v.size())

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 5009;

int n, m;
string s1, s2;

int f[N][N];
int f1[N][N], f2[N][N];
int g1[N], g2[N];

void BuildF(int f[N][N], string s1, string s2, int n, int m)
{
    FORD(i, n, 1) FORD(j, m, 1) if (s1[i] == s2[j])
        if (s1[i] == s2[j]) f[i][j] = f[i + 1][j + 1] + 1;
}

void BuildG(int g[], int f[N][N], string s, int n)
{
    FOR(i, 1, n) 
    {
        g[i] = 1;
        FOR(j, 1, n) if (i != j) maxi(g[i], f[i][j] + 1);
    }
}

void Init()
{
    n = sz(s1); m = sz(s2);
    s1 = " " + s1;
    s2 = " " + s2;

    BuildF(f1, s1, s1, n, n);
    BuildF(f2, s2, s2, m, m);
    BuildF(f, s1, s2, n, m);

    BuildG(g1, f1, s1, n);
    BuildG(g2, f2, s2, m);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> s1 >> s2;
    Init(); 

    int res = N;
    FOR(i, 1, n) FOR(j, 1, m) 
    {
        int x = max(g1[i], g2[j]);
        if (f[i][j] >= x && x) mini(res, x);
    } 

    if (res == N) res = -1;
    cout << res;

    return 0;
}