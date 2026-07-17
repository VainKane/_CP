#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define BIT(i, x) (((x) >> (i)) & 1)
#define MK(i) (1 << (i))

int const N = 409;

int m, n;
int a[N][N];

int h[N], r[N];
long long f[N];

long long Cal(int mask, int tmp[])
{
    long long res = 0;
    
    memset(h, 0, sizeof h);
    h[0] = h[n + 1] = -1;

    FOR(i, 1, m)
    {
        FOR(j, 1, n)
        {
            int memo = h[j];
            h[j] = 0;
            REP(k, 3) if (BIT(k, mask) && a[i][j] == tmp[k]) 
            {
                h[j] = memo + 1;
                break;
            }
        }

        stack<int> st;
        FOR(j, 1, n + 1)
        {
            while (!st.empty() && h[j] < h[st.top()])
            {
                r[st.top()] = j;
                st.pop();
            }
            st.push(j);
        }

        FORD(j, n, 1)
        {
            f[j] = h[j] * (r[j] - j) + f[r[j]];
            res += f[j];
        }
    }

    return res;
}

long long Solve(int x, int y, int z)
{
    int tmp[] = {x, y, z};
    long long res = 0;

    FOR(mask, 1, MK(3) - 1)
    {
        int k = __builtin_popcount(mask);
        if (k & 1) res += Cal(mask, tmp);
        else res -= Cal(mask, tmp);
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> m;
    FOR(i, 1, m)
    {
        string s; cin >> s;
        n = s.size();
        
        FOR(j, 1, n) a[i][j] = s[j - 1] - 'A';
    }

    long long res = 0;
    FOR(x, 0, 4) FOR(y, x + 1, 4) FOR(z, y + 1, 4) res += Solve(x, y, z);
    cout << res;

    return 0;
}