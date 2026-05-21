#include <bits/stdc++.h>

using namespace std;

long long a;
long long b;
int k;

long long res = 0;

bool Check(int x)
{
    deque<int> digits;
    if (x == 0) digits.push_back(0);

    while (x)
    {
        digits.push_front(x % 10);
        x /= 10;
    }

    for (int i = 1; i < digits.size(); i++)
    {
        if ((digits[i] + digits[i - 1]) % k == 0) return false;
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> a >> b >> k;
    for (int i = a; i <= b; i++) res += Check(i);

    cout << res;

    return 0;
}
