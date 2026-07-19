#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define name "MOVIE"

int const N = 1e4 + 5;

int m, n;
int e[N], l[N];

long long res = 1;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> m >> n;
    FOR(i, 1, n) cin >> e[i] >> l[i];

    int r = m;

    FOR(i, 1, n) 
    {
        // dung not thoi gian thua
        int ep = min(e[i], r / l[i]); // so tap xem them duoc
        int cnt = e[i] - ep; // so tap con lai cua phim i
        
        r -= ep * l[i];

        if (!cnt) continue; // neu da xong, tan dung ngay res de xem them

        // neu chua xong, xem tiep trong cac ngay tiep theo
        
        ep = min(cnt, m / l[i]); // so tap xem duoc moi ngay
        int d = (ep + cnt - 1) / ep; // so ngay can de cay het phim

        res += d;
        r = m - (cnt - (d - 1) * ep) * l[i];
    }   

    cout << res << ' ' << r;

    return 0;
}