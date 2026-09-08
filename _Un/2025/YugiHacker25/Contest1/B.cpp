#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define F first
#define S second
#define name "minkseq"

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 2e5 + 5;
long long const oo = 1e18;

int n, k;
pair<int, int> a[N];  

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    int t; cin >> t;
    while (t--)
    {
        cin >> n >> k;
        FOR(i, 1, n) cin >> a[i].F;
        FOR(i, 1, n) cin >> a[i].S;

        long long res = oo;

        sort(a + 1, a + n + 1);
        priority_queue<int> pq;

        long long sum = 0;
        FOR(i, 1, n)
        {
            sum += a[i].S;
            pq.push(a[i].S);
            
            if (pq.size() > k)
            {
                sum -= pq.top();
                pq.pop();
            }

            if (i >= k) mini(res, a[i].F * sum);
        }

        cout << res << '\n';
    }
}