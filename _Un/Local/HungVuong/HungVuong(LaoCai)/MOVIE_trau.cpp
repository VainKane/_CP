#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (long long i = (a), _b = (b); i <= _b; ++i)
#define name "MOVIE"

typedef long long ll;

const int N = 1e4 + 5;

ll m;            // phút xem phim mỗi ngày (1 ≤ m ≤ 1e9)
int n;           // số bộ phim (1 ≤ n ≤ 1e4)
ll e[N], l[N];   // e[i]: số tập, l[i]: độ dài mỗi tập

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".ans", "w", stdout);

    cin >> m >> n;
    FOR(i, 1, n) cin >> e[i] >> l[i];

    ll days = 1;      // bắt đầu ở ngày 1
    ll remain = m;    // phút còn trống trong ngày hiện tại

    FOR(i, 1, n)
    {
        ll cnt = e[i];          // còn cnt tập của phim i
        ll len = l[i];

        /* 1. Dùng nốt thời gian trống của ngày hiện tại */
        ll fit = min(cnt, remain / len);
        cnt    -= fit;
        remain -= fit * len;
        if (!cnt) continue;     // phim i đã xong

        /* 2. Mở thêm các ngày mới để xem trọn phim i */
        ll cap  = m / len;                  // tập / 1 ngày (>=1)
        ll need = (cnt + cap - 1) / cap;    // số ngày mới phải mở
        days   += need;

        ll last = cnt - (need - 1) * cap;   // tập xem ở ngày cuối
        remain  = m - last * len;           // phút dư của ngày đó
    }

    cout << days << ' ' << remain << '\n';
    return 0;
}
