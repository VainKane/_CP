#include <bits/stdc++.h>

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

using namespace std;

mt19937_64 rd(time(0));

long long Rand(long long l, long long r)
{
    return l + rd() * 1ll * rd() % (r - l + 1);
}

int main()
{
    ofstream cout("testcase.inp");

    int n = Rand(67, 100);

    cout << n << ' ' << (int)1e4 << '\n';
    FOR(i, 2, n) cout << Rand(1, i - 1) << ' ' << i << '\n';

    return 0;
}