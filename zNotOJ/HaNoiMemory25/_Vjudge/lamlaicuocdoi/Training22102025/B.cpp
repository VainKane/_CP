#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

int const N = 1e7 + 5;

int a, b;

int sumDiv[N];
long long pre[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> a >> b;

    FOR(i, 1, sqrt(b))
    {
        for (int j = i * i; j <= b; j += i)
        {
            sumDiv[j] += i;
            if (i * i != j) sumDiv[j] += j / i;
        }
    }

    FOR(i, 1, b) pre[i] = pre[i - 1] + abs(i - (sumDiv[i] - i));
    cout << pre[b] - pre[a - 1];

    return 0;
}