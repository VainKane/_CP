#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

int const N = 39;

int n, k, m;
int t;

long long f[N][N];
int b[N];

void Init()
{
    FOR(x, 1, min(m, n)) f[1][x] = 1;
    FOR(i, 2, k) FOR(x, 1, n) FOR(z, 1, min(x - 1, m)) f[i][x] += f[i - 1][x - z];

    cout << f[k][n] << '\n';
}

void Solve(string s)
{
    long long res = 1;
    int cnt = 0;
    int l = 1;

    s = " " + s + " ";

    FOR(i, 2, s.size() - 1)
    {
        if (s[i] == s[i - 1]) l++;
        else
        {
            b[++cnt] = l;
            l = 1;
        }
    }

    for (int i = k; i >= 1; i--)
    {
        if (i & 1)
        {
            
        } 
        else
        {
            
        }
    }

    cout << res << '\n';
} 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k >> m;
    cin >> t;

    Init();

    while (t--)
    {
        string s;
        cin >> s;
        Solve(s);               
    }

    return 0;
}