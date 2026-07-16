#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)

template <class t> mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 1e6 + 5;
long long const oo = 1e18;

int n, m;
int a[N];

long long pre[N], suf[N];
int cntPre[N], cntSuf[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    FOR(i, 1, n) cin >> a[i];

    for (int i = 1; i <= n; i += m) 
    {
        pre[i] = a[i];
        cntPre[i]++;
    }

    for (int i = n; i >= 1; i -= m) 
    {
        suf[i] = a[i];
        cntSuf[i]++;
    }

    FOR(i, 1, n) 
    {
        pre[i] += pre[i - 1];
        cntPre[i] += cntPre[i - 1];
    }
    
    FORD(i, n, 1) 
    {
        suf[i] += suf[i + 1];
        cntSuf[i] += cntSuf[i + 1];
    }

    long long res = oo;
    FOR(i, 1, n)
    {
        long long l = 1ll * cntPre[i] * a[i] - pre[i];
        long long r = suf[i] - 1ll * cntSuf[i] * a[i];

        mini(res, l + r);
    }

    cout << 2 * res;

    return 0;
}