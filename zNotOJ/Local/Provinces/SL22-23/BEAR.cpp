#include <bits/stdc++.h>

using namespace std;

int const N = 20;

int x, y;
int res = 0;

int pow3[N];

void Init()
{
    pow3[0] = 1;
    for (int i = 1; i <= 12; i++) pow3[i] = pow3[i - 1] * 3;
}

int Solve()
{
    for (int i = 0; i <= 12; i++)
    {
        if (pow3[i] * x > (1 << i) * y) return i;
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> x >> y;
    Init();

    cout << Solve();

    return 0;
}