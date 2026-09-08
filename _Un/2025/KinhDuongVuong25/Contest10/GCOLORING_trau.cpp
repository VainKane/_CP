#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define all(v) v.begin(), v.end()
#define sz(v) ((int)v.size())
#define F first
#define S second

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

int const N = 2e5 + 5;
int const oo = 1e9 + 1;

int n;
int a[N], b[N];

vector<int> vals;
long long cnt[N];

int f[8009][8009];
pair<int, long long> res;

int GetId(int const &x)
{
    return lower_bound(all(vals), x) - vals.begin() + 1;
}

void Compress()
{
    FOR(i, 1, n) 
    {
        vals.push_back(a[i]);
        vals.push_back(b[i]);
    }

    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());

    FOR(i, 1, n) 
    {
        a[i] = GetId(a[i]);
        b[i] = GetId(b[i]);
    }
}

void Sub2()
{
    Compress();

    FOR(i, 1, n) f[i][1] = a[i], cnt[a[i]]++;
    FOR(i, 1, n) f[1][i] = b[i], cnt[b[i]]++;
    cnt[a[1]]--;

    FOR(i, 2, n) FOR(j, 2, n)
    {
        f[i][j] = max(f[i - 1][j], f[i][j - 1]);
        cnt[f[i][j]]++;
    }

    FORD(i, sz(vals), 0) if (maxi(res.S, cnt[i])) res.F = vals[i - 1];
    cout << res.F << ' ' << res.S << '\n';

    exit(0);
}

void Sub3()
{
    int idx1 = n + 1;
    int idx2 = n + 1;
    
    FOR(i, 2, n) if (a[i] == 2)
    {
        idx1 = i;
        break;
    }

    FOR(i, 2, n) if (b[i] == 2)
    {
        idx2 = i;
        break;
    }

    long long cnt2 = 1ll * (n - idx1 + 1) * (n - 1);
    cnt2 += 1ll * (n - 1) * (n - idx2 + 1);
    cnt2 -= 1ll * (n - idx1 + 1) * (n - idx2 + 1);

    FOR(i, 1, n)
    {
        cnt2 += a[i] == 2;
        cnt2 += b[i] == 2;
    }

    cnt2 -= a[1] == 2;

    long long cnt1 = 1ll * n * n - cnt2;
    if (cnt1 > cnt2) cout << "1 " << cnt1 << '\n';
    else cout << "2 " << cnt2 << '\n';

    exit(0);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> a[i], vals.push_back(a[i]);
    FOR(i, 1, n) cin >> b[i], vals.push_back(b[i]);

    if (n <= 8000) Sub2();
    Sub3();

    return 0;
}